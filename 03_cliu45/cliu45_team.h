#ifndef CLIU45_TEAM_H
#define CLIU45_TEAM_H
#include "cliu45_player.h"
#include<string>
#include<vector>
using namespace std;
class Team{
public:
  string name;
  string city;
  int numofplayers;
  vector <int> playerlist;
  Team(){name = ""; city = ""; numofplayers = 0;}
  void DisplayTeam(vector <Player> &, int);
};




bool SearchTeamName(vector <Team> &, string, int);


#endif
