#ifndef LOCATIONH
#define LOCATIONH

#include "Player.h"

class Location {
protected:
  bool visited;
  char symbol;
  bool taken;

public:
  Location(char s = ' ');
  virtual int visit(Player &p);
  void SetSymbol(char userSymbol);
  void SetVisited(bool v);
  void SetTaken(bool t);
  bool GetTaken();
  virtual void draw();
  char GetSymbol();
  bool Getvisited();
  void PrintLocationInfo();
};

#endif