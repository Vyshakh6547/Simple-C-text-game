#include "Crystal.h"
#include "Player.h"

Crystal::Crystal(char s): Location(s) //: Location(s) passes the parameter s to the base
{//class constructor (in this case, Location)
  taken = false; //initialize class specific attributes here
}

void Crystal::SetTaken(bool t){
  taken=t;
}

bool Crystal::GetTaken(){
  return taken;
}

void Crystal::draw(){
  if (visited == true && taken == false){
    cout << symbol << endl;
  }
  else if (taken == true){
    cout << " " << endl;
  }
  else{
    cout << "." << endl;
  }
}

int Crystal::visit(Player &p){
  if(!visited){
    visited=true;
    cout << "You found a magic crystal." << endl;
  }
  return 1;
}
