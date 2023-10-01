#ifndef CRYSTALH
#define CRYSTALH
#include "Location.h"
#include "Player.h"

class Crystal : public Location{
  private:
    bool taken;
  public:
    Crystal(char s);
    virtual int visit(Player &p);
    virtual void draw();
};

#endif
