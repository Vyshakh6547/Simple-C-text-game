#include "Portal.h"
#include "Player.h"

Portal::Portal(char s)
    : Location(s) //: Location(s) passes the parameter s to the base
{                 // class constructor (in this case, Location)
  taken = false;  // initialize class specific attributes here
}

void Portal::SetTaken(bool t) { taken = t; }

bool Portal::GetTaken() { return taken; }

void Portal::draw() {
  /*
  if (visited == true && taken == false) {
    cout << symbol;
  } else if (taken == true) {
    cout << "O";
  } else {
    cout << "X";
  }
*/
  if(!taken){
    cout<<"X";
  }else {
    cout<<symbol;
  }
}

int Portal::visit(Player &p) {
  if (!visited) {
    visited = true;
    if (!taken) {
      cout << "You found a Massive Door with a sphinx's heiroglyphs on it, perhaps finding it would help open the door." << endl;
    }
  }

  if(taken){
    cout << "The door has been opened, the key disappears into dust. You found a Magic Portal." << endl;
  }
  return 1;
}
