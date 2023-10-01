#include "Location.h"

Location::Location(char s){
  s=' ';
  visited=false;
  symbol=s;
}

virtual int Location::visit(Player &p){
  visited=true;
  return 1;
}
virtual void Location::draw(){
  if(visited){
    cout << symbol << endl;
  }
  else{
    cout << "." << endl;
  }
}
char Location::Getsymbol(){
  return symbol;
}
bool Location::Getvisited(){
  return visited;
}
void Location::PrintLocationInfo(){
  cout << "Location visited: " << visited << " " << "Location symbol: " << symbol << endl;
}
