#include "Sphinx.h"
#include "Player.h"

Sphinx::Sphinx(char s)
    : Location(s) //: Location(s) passes the parameter s to the base
{                 // class constructor (in this case, Location)
  taken = false;  // initialize class specific attributes here
}

void Sphinx::SetTaken(bool t) { taken = t;}

bool Sphinx::GetTaken() { return taken; }

void Sphinx::draw() {
  if (visited == true && taken == false) {
    cout << symbol;
  } else if (taken == true) {
    cout << " ";
  } else {
    cout << ".";
  }
}

int Sphinx::visit(Player &p) {
  if (!visited) {
    visited = true;
    cout
        << "The mythical Sphinx appears in front of you, its royal face lit up "
           "by the scorching desert sun. It looks at you with eyes that appear "
           "to be filled with millennia of wisdom. Your intelligence and "
           "resolve will be put to the test as the Sphinx speaks, its voice a "
           "frightening echo in the desert's emptiness. The realisation that "
           "you must solve its riddle in order to move forward in your search "
           "for the remaining crystals and eventually arrive at the portal for "
           "your chance to leave this merciless desert makes your heart race."
        << endl;
  }
  if (taken) {
    cout << "The altar stands tall, yet the presense of the Sphinx is all but "
            "gone"
         << endl;
  }
  return 1;
}
