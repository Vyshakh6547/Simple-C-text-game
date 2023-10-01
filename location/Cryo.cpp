#include "Cryo.h"
#include "Player.h"

Cryo::Cryo(char s): Location(s) //: Location(s) passes the parameter s to the base
{//class constructor (in this case, Location)
  taken = false; //initialize class specific attributes here
}

void Cryo::draw(){
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

int Cryo::visit(Player &p){
  if(!visited){
    visited=true;
    cout << "You found a magic cryo." << endl;
  }
  return 1;
}
