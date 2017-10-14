#ifndef CLIU45_PLAYER_H
#define CLIU45_PLAYER_H
#include<string>
using namespace std;
typedef struct player{
  string team;
  string name;
  int id;
  string phonenumber;
  string position;
  string address;
  double salary;
}player;


bool SearchPlayerId(player *, int, int);

bool SearchPlayerPhone(player *, string, int);

void FindWithName(player *, string, int);

void FindWithId(player *, int, int);

void FindWithPhone(player *, string, int);

void SortWithName(player *, int, string);

void SortWithId(player *, int, string);


void SortWithSalary(player *, int ,string);

#endif
