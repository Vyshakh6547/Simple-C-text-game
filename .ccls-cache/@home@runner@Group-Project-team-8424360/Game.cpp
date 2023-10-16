#include "Game.h"
#include "Crystal.h"
#include "Location.h"
#include "Oasis.h"
#include "Player.h"
#include "Portal.h"
#include "Sphinx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// constructor: set all variables to 0 or null
Game::Game() {
  world = nullptr;
  rows = 0;
  cols = 0;
  playerRow = 0;
  playerCol = 0;
  water = 0;
  Pr = 0;
  Pc = 0;
}

// destructor: delete all allocated spaces
Game::~Game() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      delete world[i][j];
    }
  }
}

/*
set up the rows and column of the game map, set the initial positon(row, column)
of the player then set every location of the map randomly to "empty", "crystal",
or "Oasis"
*/
void Game::setWater(int &InitWater) { water = InitWater; }
void Game::setUpGame(ifstream &Data) {
  int r, c;
  Data >> r >> c;
  cout << r << c;
  // cout << r << " " << c << endl;
  // int ran;//random seed to determine the item at each location
  rows = r;
  cols = c;
  Data.ignore();
  playerCol = 0;
  playerRow = 0;
  world = new Location **[rows];
  for (int i = 0; i < rows; i++) {
    world[i] = new Location *[cols];
  }
  string readLine;
  string readPos;
  for (int i = 0; i < rows; i++) {
    getline(Data, readLine);
    stringstream ss(readLine);
    for (int j = 0; j < cols; j++) {
      getline(ss, readPos, ' ');
      // cout << "("<< i << "," << j << ")" << readPos << endl;
      if (readPos == "o") {
        world[i][j] = new Location(' ');
      } else if (readPos == "Crystal") {
        world[i][j] = new Crystal('C');
      } else if (readPos == "Oasis") {
        world[i][j] = new Oasis('W');
      } else if (readPos == "Sphinx") {
        world[i][j] = new Sphinx('S');
      } else if (readPos == "Portal") {
        world[i][j] = new Portal('O');
        Pr = i;
        Pc = j;
      } else {
        cout << "unknown location type! at" << i << "," << j
             << " Please check your Data file." << endl;
      }
    }
  }

  world[0][0]->visit(p);
}
/*
prompt the user to move, the player's position on the map will change according
to the input of the user
*/
void Game::move() {
  char direction;
  cout << "What direction do you want to move <u, d, l, r>? ";
  cin >> direction;
  cout << endl;

  // the player can choose 4 directions
  // when moving to a new location, the player will mark it as visited
  if (direction == 'u') {
    if (playerRow > 0) {
      world[--playerRow][playerCol]->visit(p);
    }
  } else if (direction == 'd') {
    if (playerRow < (rows - 1)) {
      world[++playerRow][playerCol]->visit(p);
    }
  } else if (direction == 'l') {
    if (playerCol > 0) {
      world[playerRow][--playerCol]->visit(p);
    }
  } else if (direction == 'r') {
    if (playerCol < (cols - 1)) {
      world[playerRow][++playerCol]->visit(p);
    }
  } else {
    cout << "   Please enter the correct direction!" << endl;
    cout << endl;
    this->move();
  }
  water--;
}
// draw the game map
void Game::drawGame() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == playerRow && j == playerCol) {
        cout << 'P';
      } else {
        world[i][j]->draw();
      }
    }
    cout << endl;
  }
}

// the overall gameplay, the player will be prompted to explore the map again
// and again until the player wants to quit
void Game::playGame(ifstream &Data) {
  int countCrystal = 0;
  this->setUpGame(Data);
  char in;
  char next;
  do {
    cout << "you have " << water << " water left" << endl;
    this->drawGame();
    this->move();
    if (world[playerRow][playerCol]->GetSymbol() == 'C') {
      countCrystal++;
    }
    if (world[playerRow][playerCol]->GetSymbol() == 'W' && water < 30) {
      water += 10;
    }
    if (countCrystal > 3 && world[Pr][Pc]->GetTaken()) {
      cout << "Victory!" << endl;
      break;
    }
    if (water < 1) {
      cout << "You ran out of water! You lose consciousness.";
      break;
    }

    cout << "You have found " << countCrystal << " crystals so far" << endl;
    cout << "Press any key to continue...(press Q to quit)";
    cin.ignore();
    next = cin.get();

    system("clear");
    cout << endl;
  } while (next != 'Q');
}