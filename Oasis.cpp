#include "Oasis.h"
#include "Player.h"

Oasis::Oasis(char s): Location(s) //: Location(s) passes the parameter s to the base
{//class constructor (in this case, Location)
  taken = false; //initialize class specific attributes here
}

void Oasis::SetTaken(bool t){
  taken=t;
}
bool Oasis::GetTaken(){
  return taken;
}
void Oasis::draw(){
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

int Oasis::visit(Player &p){
  if(!visited){
    visited=true;
    cout << "You found an Oasis." << endl;
  }
  return 1;
}
