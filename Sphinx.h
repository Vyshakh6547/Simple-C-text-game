#ifndef SPHINXH
#define SPHINXH
#include "Location.h"
#include "Player.h"

class Sphinx : public Location{
  private:
    bool taken;
  public:
    Sphinx(char s);
    void SetTaken(bool t);
    bool GetTaken();
    virtual int visit(Player &p);
    virtual void draw();
};

#endif