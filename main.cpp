#include <iostream>
#include "Player.h"
using namespace std;

void createNewPlayer(Player (&players)[20], int i){
  if(i>=20 || i<0){
    cout<<"Invalid index!"<<endl;
  } else{
    string name;
    int age;
    cout<<"Set the name for player "<<i<<endl;
    getline(cin,name);
    players[i].SetName(name);
    cout<<"Set the age for player "<<i<<endl;
    cin>>age;
    players[i].SetAge(age);
    cout<<"Sucessfully set name and age for player"<<i<<endl;
  }
}

void modifyPlayer(Player (&players)[20], string n){
  bool check=false;
  for(int i = 0; i<20; i++){
    if(n.compare(players[i].GetName())==0){
      check = true;
      cout<<"What do you want to modify? (name/age)"<<endl;
      string choice;
      cin>>choice;
      cin.ignore();
      if(choice.compare("name") == 0){
        string newName;
        cout<<"Enter a new name:"<<endl;
        getline(cin,newName);
        players[i].SetName(newName);
        cout<<"Successfully set the new name."<<endl;
      }
      else if(choice.compare("age") == 0){
        int newAge;
        cout<<"Enter a new age:"<<endl;
        cin>>newAge;
        players[i].SetAge(newAge);
        cout<<"Successfully set the new age."<<endl;
      }
      else{
        cout << "Error: please input correct attribute" << endl;
      }
    }
  }
  if(!check){
    cout << "This name is not in the list of Players" << endl;
  }
}
void printPlayers(Player players[],int t){
  for(int i=0;i<t;i++){
    players[i].PrintPlayerInfo();
  }
}
int main() {
  string inputname;
  int index,total;
  Player players[20];
  total = 20;
  cout << "Input an index: " << endl;
  cin >> index;
  cin.ignore();
  createNewPlayer(players, index);
  cout << "Input a Name: " << endl;
  cin.ignore();
  getline(cin,inputname);
  modifyPlayer(players,inputname);
  printPlayers(players,total);
}