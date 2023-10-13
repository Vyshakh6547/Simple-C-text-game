#ifndef PORTALH
#define PORTALH
#include "Location.h"
#include "Player.h"

class Portal : public Location{
  private:
    bool taken;
  public:
    Portal(char s);
    void SetTaken(bool t);
    bool GetTaken();
    virtual int visit(Player &p);
    virtual void draw();
};

#endif