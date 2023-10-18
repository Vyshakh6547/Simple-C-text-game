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
  Heat = 1;
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
int Game::getWater() { return water; }
void Game::setHeat(int &heat) { Heat = heat; }
int Game::getHeat() { return Heat; }
void Game::setUpGame(ifstream &Data) {
  int r, c;
  Data >> r >> c;
  // cout << r << c;
  //  cout << r << " " << c << endl;
  //  int ran;//random seed to determine the item at each location
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
    } else {
      cout << "You can't move there - there is a duststorm strong enough to "
              "push you back!"
           << endl;
    }
  } else if (direction == 'd') {
    if (playerRow < (rows - 1)) {
      world[++playerRow][playerCol]->visit(p);
    } else {
      cout << "You can't move there - there is a duststorm strong enough to "
              "push you back!"
           << endl;
    }
  } else if (direction == 'l') {
    if (playerCol > 0) {
      world[playerRow][--playerCol]->visit(p);
    } else {
      cout << "You can't move there - there is a duststorm strong enough to "
              "push you back!"
           << endl;
    }
  } else if (direction == 'r') {
    if (playerCol < (cols - 1)) {
      world[playerRow][++playerCol]->visit(p);
    } else {
      cout << "You can't move there - there is a duststorm strong enough to "
              "push you back!"
           << endl;
    }
  } else {
    cout << "   Please enter the correct direction!" << endl;
    cout << endl;
    this->move();
  }
  water = water - Heat;
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
  int countCrystal = 0, ansd = 0;
  this->setUpGame(Data);
  char in;
  char next;
  int ran;
  bool kill = false;
  ran = rand();
  do {
    cout << "you have " << water << " water left" << endl;
    this->drawGame();
    this->move();

    if (water < 1) {
      cout << "You ran out of water! You lose consciousness. Game over.";
      break;
    }

    if (world[playerRow][playerCol]->GetSymbol() == 'C') {
      countCrystal++;
    }
    if (world[playerRow][playerCol]->GetSymbol() == 'W' && water < 60) {
      water = 60;
    }
    if (world[playerRow][playerCol]->GetSymbol() == 'S' &&
        !world[playerRow][playerCol]->GetTaken()) {
      cout << "There is a circular altar in front of the sphinx, with sand all "
              "over , You believe that is where you stand to face the sphinx's "
              "riddles. Keep in mind, sphinx is a dangerous entity, proceed "
              "only if you are confident in solving the riddles. Would you "
              "like to step up (y/n)."
           << endl;
      char altar;
      cin >> altar;
      if (altar == 'y') {
        cout << "You walk up to the altar, and hear a voice speaking from "
                "inside."
             << endl;
        string answer;

        while (ansd < 3) {
          if (ran % 3 == 0) {
            cout
                << "\"Never resting, never still; moving silently from hill to "
                   "hill; it does not walk, run or trot; all is cool where it "
                   "is not.\"";

            cin >> answer;
            if (answer == "Sun" || answer == "sun") {
              cout << "Correct answer" << endl;
              ansd++;
              ran++;
            } else {
              cout << "Wrong answer" << endl;
              if (countCrystal > 0) {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal."
                     << endl;
                countCrystal--;
              } else {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal. ";
                cout << "Unfortunately, you have no crystal, and the sphinx "
                        "drains your life. Game over."
                     << endl;
                kill = true;
                break;
              }
            }
          } else if (ran % 3 == 1) {
            cout << "\"What goes on four feet in the morning, two feet in "
                    "midday, and three feet in the evening?\"";

            cin >> answer;
            if (answer == "Man" || answer == "man" || answer == "Human" ||
                answer == "human") {
              cout << "Correct answer" << endl;
              ansd++;
              ran++;
            } else {
              cout << "Wrong answer" << endl;
              if (countCrystal > 0) {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal."
                     << endl;
                countCrystal--;
              } else {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal. ";
                cout << "Unfortunately, you have no crystal, and the sphinx "
                        "drains your life. Game over."
                     << endl;
                kill = true;
                break;
              }
            }
          } else if (ran % 3 == 2) {
            cout << "\" Round she is, yet flat as a board,Altar of the Lupine "
                    "Lords,Jewel on black velvet, pearl in the sea,Unchanged "
                    "but "
                    "e’erchanging, eternally \"";
            cin >> answer;
            if (answer == "Moon" || answer == "moon") {
              cout << "Correct answer" << endl;
              ansd++;
              ran++;
            } else {
              cout << "Wrong answer" << endl;
              if (countCrystal > 0) {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal."
                     << endl;
                countCrystal--;
              } else {
                cout << "The sphinx will spare your life, in exchange for a "
                        "crystal. ";
                cout << "Unfortunately, you have no crystals, and the sphinx "
                        "drains your life. Game over."
                     << endl;
                kill = true;
                break;
              }
            }
          }
        }

        if (kill) {
          break;
        }

        if (ansd == 3) {
          cout << "\"Impressive, traveler,\" it intones. \"You have proven "
                  "your intelligence and resourcefulness. May your path be "
                  "guided by the light of knowledge.\" With these words, The "
                  "sphinx disappears and leaves behind a Key and a Crystal on "
                  "the altar."
               << endl;
          countCrystal++;
          ((Sphinx *)world[playerRow][playerCol])->SetTaken(true);
          ((Portal *)world[Pr][Pc])->SetTaken(true);
        }
      } else {
        cout << "You walk away from the altar" << endl;
      }
    }

    if (world[playerRow][playerCol]->GetSymbol() == 'O' &&
        ((Portal *)world[Pr][Pc])->GetTaken()) {
      if (countCrystal >= 3) {
        cout << "Victory!" << endl;
        break;
      } else {
        cout << "You need " << (3 - countCrystal)
             << " more crystals to power up the portal." << endl;
      }
    }

    cout << "You have found " << countCrystal << " crystals so far." << endl;
    cout << "Press any key to continue...(press Q to quit)";
    cin.ignore();
    next = cin.get();

    system("clear");
    cout << endl;
  } while (next != 'Q');
}