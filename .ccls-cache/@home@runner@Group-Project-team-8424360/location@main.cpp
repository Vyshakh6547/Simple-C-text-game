#include <iostream>
#include "Player.h"
#include "Location.h"
#include "Crystal.h"
#include "Cryo.h"

int main(){
  Player p("Alice Bob",23);
  char t=' ';
  Location Paris(t);
  Crystal Test(t);
  Cryo tie(t);
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
}