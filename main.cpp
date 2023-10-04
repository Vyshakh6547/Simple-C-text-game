#include <iostream>
#include "Player.h"
#include "Location.h"
#include "Crystal.h"
#include "Cryo.h"
#include "Game.h"

int main(){
  Player p("Alice Bob",23);
  /*
  char t=' ';
  char crystal = 'C';
  char cryo = 'c';
  Location Paris(t);
  Crystal Test(crystal);
  Cryo tie(cryo);
  Paris.draw();
  Test.draw();
  tie.draw();
  Paris.visit(p);
  Test.visit(p);
  tie.visit(p);
  Paris.draw();
  Test.draw();
  tie.draw();
  Test.SetTaken(true);
  tie.SetTaken(true);
  Test.draw();
  tie.draw();
  */
  Game game;
  game.playGame(4, 4, 0, 0);
  return 0;
}