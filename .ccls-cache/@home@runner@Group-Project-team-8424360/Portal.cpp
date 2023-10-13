#include "Portal.h"
#include "Player.h"

Portal::Portal(char s): Location(s) //: Location(s) passes the parameter s to the base
{//class constructor (in this case, Location)
  taken = false; //initialize class specific attributes here
}

void Portal::SetTaken(bool t){
  taken=t;
}

bool Portal::GetTaken(){
  return taken;
}

void Portal::draw(){
  if (visited == true && taken == false){
    cout << symbol;
  }
  else if (taken == true){
    cout << "O";
  }
  else{
    cout << ".";
  }
}


int Portal::visit(Player &p){
  if(!visited){
    visited=true;
    if(taken){
      cout << "You found a Magic Portal." << endl;
    }
    else{
      cout << "You found a Massive Door." << endl;
    }
  }
  return 1;
}
