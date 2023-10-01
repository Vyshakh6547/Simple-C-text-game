#ifndef CRYOH
#define CRYOH
#include "Location.h"
#include "Player.h"

class Cryo : public Location{
  private:
    bool taken;
  public:
    Cryo(char s);
    void SetTaken(bool t);
    bool GetTaken();
    virtual int visit(Player &p);
    virtual void draw();
};

#endif