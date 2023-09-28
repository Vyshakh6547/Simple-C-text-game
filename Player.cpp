#include "Player.h"
#include <string>
using namespace std;

Player::Player(){
  name="unknown ";
  age=-1;
}

Player::Player(string n, int a){
  name = n;
  age = a;
}

void Player::SetAge(int userAge){
  age=userAge;
}
void Player::SetName(string userName){
  name=userName;
}
int Player::GetAge(){
  return age;
}
string Player::GetName(){
  return name;
}
void Player::PrintPlayerInfo(){
  cout << "Player Name: " << name << " " << "Player Age: " << age << endl;
}