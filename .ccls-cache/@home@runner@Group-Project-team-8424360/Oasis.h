#ifndef OASISH
#define OASISH
#include "Location.h"
#include "Player.h"

class Oasis : public Location{
  private:
    bool taken;
  public:
    Oasis(char s);
    void SetTaken(bool t);
    bool GetTaken();
    virtual int visit(Player &p);
    virtual void draw();
};

#endif