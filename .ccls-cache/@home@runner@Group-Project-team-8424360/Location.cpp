#include "Location.h"
#include "Player.h"

Location::Location(char s){
  visited=false;
  symbol=s;
}

int Location::visit(Player &p){
  visited=true;
  return 1;
}
void Location::draw(){
  if(visited){
    cout << symbol;
  }
  else{
    cout << ".";
  }
}
char Location::GetSymbol(){
  return symbol;
}
bool Location::Getvisited(){
  return visited;
}
void Location::SetSymbol(char userSymbol){
  symbol = userSymbol;
}
void Location::SetVisited(bool v){
  visited = v;
}
void Location::PrintLocationInfo(){
  cout << "Location visited: " << visited << " " << "Location symbol: " << symbol << endl;
}
