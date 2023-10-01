#ifndef LOCATIONH
#define LOCATIONH

#include <iostream>

class Location {
  protected:
    bool visited;
    char symbol;
  
  public:
    Location(char s=' ');
    void visit(Player &p);
    void SetSymbol(char userSymbol);
    int draw();
    string GetSymbol();
    void PrintPlayerInfo();
    
};




#endif