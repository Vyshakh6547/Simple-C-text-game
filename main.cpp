#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Location.h"
#include "Crystal.h"
#include "Sphinx.h"
#include "Cryo.h"
#include "Game.h"
#include <fstream>
#include <sstream>

int main(){
  int level;
  ifstream Data;
  cout<<"Choose the difficulty level(enter 1 for easy and 2 for hard): ";
  cin>>level;
  if(level == 1){
    Data.open("Easy.txt", ios::in);
  }

  if(level == 2){
    Data.open("Hard.txt", ios::in);
  }
  
  if(level!=1&&level!=2){
    cout << "Error! input not recognised. please input a number 1 or 2";
  }
  
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
  game.playGame(Data);
  Data.close();
  return 0;
}