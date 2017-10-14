#ifndef CLIU45_TEAM_H
#define CLIU45_TEAM_H
#include "cliu45_player.h"
#include<string>
using namespace std;
typedef struct playerlist{
  int index;
  int id;
  struct playerlist *next;
}playlist;

typedef struct team{
  string name;
  string city;
  int numofplayers;
  playerlist member;
  team *next;
}team;

void DisplayTeam(team*, string, player*);

bool SearchTeamName(team*, string);

void ChangeIndex(team *, int, player *);

#endif
