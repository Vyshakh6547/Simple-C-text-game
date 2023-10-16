#include "Crystal.h"
#include "Game.h"
#include "Location.h"
#include "Oasis.h"
#include "Player.h"
#include "Sphinx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main() {
  int level;
  ifstream Data;
  int InitWater;
  cout << "Game Instruction:" << endl;
  cout << "As you open your eyes, you find yourself in a seemingly endless "
          "desert. You walk endlessly and as you are almost losing "
          "consciousness, you see an oasis in the distance. Mirage or "
          "otherwise, you gather the last of your strength to move towards "
          "your last hope. As luck would have it, you discover an Oasis and a "
          "hut. The hut seems abandoned and worn out by time and sand, inside "
          "which, you find bedding, a compass, a water canister, and a map on "
          "the wall with writings in a language unknown to you but has an X "
          "marked on it. You set out to find an exit but be mindful of the "
          "water you carry."
       << endl;
  cout << endl;
  cout << "Choose the difficulty level(enter 1 for Beach fun and 2 for "
          "Scorching Earth): ";
  cin >> level;
  Data.open("Data.txt");
  if (level == 1) {
    InitWater = 30;
  }

  if (level == 2) {
    InitWater = 20;
  }
  if (level != 1 && level != 2) {
    cout << "Error! input not recognised. please input a number 1 or 2";
  }
  Game game;
  game.setWater(InitWater);
  game.playGame(Data);
  Data.close();
  return 0;
}