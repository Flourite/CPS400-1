#ifndef CLIU45_PLAYER_H
#define CLIU45_PLAYER_H
#include<string>
#include<vector>
using namespace std;
class Player{
public:
  string team;
  string name;
  int id;
  string phonenumber;
  string position;
  string address;
  double salary;
  Player(){
    team = "";
    name = "";
    id = 0;
    phonenumber = "";
    position = "";
    address = "";
    salary = 0;
  }
};



bool SearchPlayerId(vector <Player> &, int, int);

bool SearchPlayerPhone(vector <Player> &, string, int);

void FindWithName(vector <Player> &, string, int);

void FindWithId(vector <Player> &, int, int);

void FindWithPhone(vector <Player> &, string, int);

void SortWithName(vector <Player> &, int, string);

void SortWithId(vector <Player> &, int, string);


void SortWithSalary(vector <Player> &, int ,string);

#endif
