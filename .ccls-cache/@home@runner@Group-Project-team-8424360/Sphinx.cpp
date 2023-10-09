#include "Sphinx.h"
#include "Player.h"

Sphinx::Sphinx(char s): Location(s) //: Location(s) passes the parameter s to the base
{//class constructor (in this case, Location)
  taken = false; //initialize class specific attributes here
}

void Sphinx::draw(){
  if (visited == true && taken == false){
    cout << symbol;
  }
  else if (taken == true){
    cout << " ";
  }
  else{
    cout << ".";
  }
}

int Sphinx::visit(Player &p){
  if(!visited){
    visited=true;
    cout << "You are killed by a Sphinx, game over." << endl;
  }
  return 1;
}
