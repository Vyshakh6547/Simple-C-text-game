#ifndef GAMEH
#define GAMEH

#include "Location.h"
#include "Player.h"

class Game {

private:
  Location ***world;
  Player p;
  int rows;
  int cols;
  int playerRow; //current player location row and column
  int playerCol;
  int water; // current amount of water
  int Heat; // difficulty
  int Pr; // Portal location row and column
  int Pc;

public:
  ~Game();
  Game();
  void setUpGame(ifstream &Data);
  void move();
  void setWater(int &InitWater);
  void setHeat(int &heat);
  int getWater();
  int getHeat();
  void drawGame();
  void playGame(ifstream &Data);
};

#endif