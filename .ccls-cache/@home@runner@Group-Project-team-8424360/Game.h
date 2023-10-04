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
  
  

  public:
    ~Game();
    Game();
    void setUpGame(int r, int c, int pr, int pc);
    void move();
    void drawGame();
    void playGame(int r, int c, int pr, int pc);

      
};

#endif