#include <iostream>
#include "Location.h"
#include "Player.h"
#include "Game.h"
using namespace std;

Game::Game(){
  world = nullptr;
  rows = 0;
  cols = 0;
  playerRow = 0;
  playerCol = 0;
  
}

void Game::setUpGame(int r, int c, int pr, int pc){
  rows = r;
  cols = c;
  playerCol = pc;
  playerRow = pr;
  world = new (Location**)[r];
  for (int i = 0; i < r; ++i) {
    world[i] = new (Location*)[c];
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      world[i][j] = NULL;
    }
  }
}

void Game::playGame(){
  
}