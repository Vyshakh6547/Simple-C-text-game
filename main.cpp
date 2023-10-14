#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

void createNewPlayer(Player(&players)[20], int i) {
    if (i >= 20 || i < 0) {
        cout << "Invalid index!" << endl;
    }
    else {
        string name;
        int age;
        cout << "Set the name for player " << i << endl;
        getline(cin, name);
        players[i].SetName(name);
        cout << "Set the age for player " << i << endl;
        cin >> age;
        players[i].SetAge(age);
        cin.ignore();
        cout << "Sucessfully set name and age for player" << i << endl;
    }
}
void modifyPlayer(Player(&players)[20], string n) {
    vector<int> dup;
    int playernum = -1;
    bool check = false;

    do {
        for (int i = 0; i < 20; i++) {
            //cout << n << " " << players[i].GetName() << endl;
            if (n.compare(players[i].GetName())==0) {
                //cout << "Found player " << i << endl;
                dup.push_back(i);
                cout << dup.size();
            }
        }
        if (dup.size() > 1) {
            cout << "There are multiple players with that first name. Please provide "
                "your age/id, or to quit press \" q \" "
                << endl;
            string checkage;
            cin >> checkage;
            if (checkage == "q") {
                break;
            }
            do {
                for (int i : dup) {
                    if (players[i].GetAge() ==
                        stoi(checkage)) { // we can add a check in the same way for a new
                        // private variable like id(unique).
                        playernum = i;
                        check = true;
                    }
                }
                if (!check) {
                playeragecheck:
                    cout << "Could not find a player with input attributes.please check your input. If you want to reinput please press \" y \" or to quit press \" n \""<< endl;
                    char conti;
                    cin >> conti;
                    if (conti == 'n') {
                        break;
                    }
                    else if (conti == 'y') {
                        cout << " please re-enter the age/id:";
                        cin >> checkage;
                    }
                    else {
                        cout << "unknown input";
                        goto playeragecheck;
                    }
                }
            } while (!check);
        }
        else if (dup.size() == 1) {
            cout << "Player found." << endl;
            playernum = dup[0];
            check = true;
        }
        else {
          playernamecheck:
            cout << "This name is not in the list of Players. Please reinput the "
                "name after the prompt \" y \" or to quit press \" n \" "
                << endl;
            char cont;
            cin >> cont;
            if (cont == 'n') {
                break;
            }
            else if (cont == 'y') {
                cout << " please re-enter the name:";
                cin >> n;
            }
          else{
            cout << "unknown input";
            goto playernamecheck;
          }
        }
    } while (!check);

    if (check) {
        cout << "What do you want to modify ? (name / age)" << endl;
        string choice;
        cin >> choice;
        cin.ignore();
        if (choice.compare("name") == 0) {
            string newName;
            cout << "Enter a new name:" << endl;
            getline(cin, newName);
            players[playernum].SetName(newName);
            cout << "Successfully set the new name." << endl;
        }
        else if (choice.compare("age") == 0) {
            int newAge;
            cout << "Enter a new age:" << endl;
            cin >> newAge;
            players[playernum].SetAge(newAge);
            cout << "Successfully set the new age." << endl;
        }
        else {
            cout << "Error: please input correct attribute" << endl;
        }
    }
    cout << "function has ended" << endl;
}

void printPlayers(Player players[], int t) {
    for (int i = 0; i < t; i++) {
        players[i].print();
    }
}
int main() {
    string inputname;
    int total;
    Player players[20];
    total = 20;
    for (int i = 0; i < 3; i++) {
        createNewPlayer(players, i);
    }
    cout << "Input a Name: " << endl;
    getline(cin, inputname);
    cout << inputname;
    modifyPlayer(players, inputname);
    printPlayers(players, total);
}