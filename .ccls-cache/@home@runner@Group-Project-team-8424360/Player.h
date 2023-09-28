#ifndef PLAYERH
#define PLAYERH

#include <iostream>
#include <string>
using namespace std;

class Player {
  private:
    string name;
    int age;
  
  public:
    Player();
    Player(string n, int a);
    void SetAge(int userAge);
    void SetName(string userName);
    int GetAge();
    string GetName();
    void PrintPlayerInfo();
    
};



#endif