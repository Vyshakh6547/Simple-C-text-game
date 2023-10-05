#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Location.h"
#include "Crystal.h"
#include "Cryo.h"
#include "Player.h"
#include "Game.h"
using namespace std;

//constructor: set all variables to 0 or null
Game::Game(){
  world = nullptr;
  rows = 0;
  cols = 0;
  playerRow = 0;
  playerCol = 0;
  
}

//destructor: delete all allocated spaces
Game::~Game(){
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      delete world[i][j];
    }
  }
}

/*
set up the rows and column of the game map, set the initial positon(row, column) of the player
then set every location of the map randomly to "empty", "crystal", or "cryo"  
*/
void Game::setUpGame(int r, int c, int pr, int pc){
  int ran;//random seed to determine the item at each location
  rows = r;
  cols = c;
  playerCol = pc;
  playerRow = pr;
  world = new Location** [rows];
  for (int i = 0; i < rows; i++) {
    world[i] = new Location* [cols];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      //if world[i][j] is the origin of the player, set it as empty location(visited)
      if(i == playerRow && j == playerCol){
        world[i][j] = new Location(' ');
        world[i][j]->visit(p);
      }else{
        ran = rand() % 3;//generate a random item for the location
        if(ran == 0){
          world[i][j] = new Location(' ');
        }else if(ran == 1){
          world[i][j] = new Crystal('C');
        }else if(ran == 2){
          world[i][j] = new Cryo('c');
        }
      }
    }
  }
  
}
/*
prompt the user to move, the player's position on the map will change according to the input of the user
*/
void Game::move(){
  char direction;
  cout<<"What direction do you want to move <u, d, l, r>? ";
  cin>>direction;
  cout<<endl;
  
  //the player can choose 4 directions
  //when moving to a new location, the player will mark it as visited
  if(direction == 'u'){
    if(playerRow>0){
      world[--playerRow][playerCol]->visit(p);
    }
  }else if(direction == 'd'){
    if(playerRow<(rows-1)){
      world[++playerRow][playerCol]->visit(p);
    }
  }else if(direction == 'l'){
    if(playerCol>0){
      world[playerRow][--playerCol]->visit(p);
    }
  }else if(direction == 'r'){
    if(playerCol<(cols-1)){
      world[playerRow][++playerCol]->visit(p);
    }
  }else {
    cout<<"   Please enter the correct direction!"<<endl;
    cout<<endl;
    this->move();
  }
}
//draw the game map
void Game::drawGame(){
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(i == playerRow && j == playerCol){
        cout<<'P';
      }else{
        world[i][j]->draw();
      }
    }
    cout<<endl;
  }
}
//the overall gameplay, the player will be prompted to explore the map again and again until the player wants to quit
void Game::playGame(int r, int c, int pr, int pc){
  this->setUpGame(r, c, pr, pc);
  char in;
  char next;
  do{
    this->drawGame();
    this->move();
    cout<<"Press any key to continue...(press Q to quit)";
    cin.ignore();
    next = cin.get();
    system("clear");
    cout<<endl;
  }while(next!='Q');
    
}