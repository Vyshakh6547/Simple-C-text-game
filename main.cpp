#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Location.h"
#include "Crystal.h"
#include "Sphinx.h"
#include "Oasis.h"
#include "Game.h"
#include <fstream>
#include <sstream>

int main(){
  int level;
  ifstream Data;
  int startingwater;
  cout<<"Game Instruction:"<<endl;
  cout<<"As you open your eyes, you find yourself in a seemingly endless desert. You walk endlessly and as you are almost losing consciousness, you see an oasis in the distance. Mirage or otherwise, you gather the last of your strength to move towards your last hope. As luck would have it, you discover an Oasis and a hut. The hut seems abandoned and worn out by time and sand, inside which, you find bedding, a compass, a water canister, and a map on the wall with writings in a language unknown to you but has an X marked on it. You set out to find an exit but be mindful of the water you carry."<<endl;
  cout<<endl;
  cout<<"Choose the difficulty level(enter 1 for Beach fun and 2 for Scorching Earth): ";
  cin>>level;
  Data.open("Data.txt", ios::in);
  if(level == 1){
    startingwater=30;
  }

  if(level == 2){
    startingwater=10;
  }
  if(level!=1&&level!=2){
    cout << "Error! input not recognised. please input a number 1 or 2";
  }
  
    /*
  char t=' ';
  char crystal = 'C';
  char Oasis = 'c';
  Location Paris(t);
  Crystal Test(crystal);
  Oasis tie(Oasis);
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