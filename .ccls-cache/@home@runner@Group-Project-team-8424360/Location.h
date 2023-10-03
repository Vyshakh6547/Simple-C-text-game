#ifndef LOCATIONH
#define LOCATIONH


#include "Player.h"

class Location {
  protected:
    bool visited;
    char symbol;
  
  public:
    Location(char s=' ');
    virtual int visit(Player &p);
    void SetSymbol(char userSymbol);
    void SetVisited(bool v);
    virtual void draw();
    char GetSymbol();
    bool Getvisited();
    void PrintLocationInfo();
    
};




#endif