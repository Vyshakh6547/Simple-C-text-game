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
  int playerRow;
  int playerCol;
  int water;
  int Heat; // difficulty
  int Pr;
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