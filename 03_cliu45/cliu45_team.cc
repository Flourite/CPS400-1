#include "cliu45_team.h"
#include "cliu45_player.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
void Team::DisplayTeam(vector <Player> &p, int num){
  int ind;
  for (int i = 1;i <= numofplayers;i++){
    ind = playerlist[i];
    for (int j = 1;j <= num;j++){
      if (ind == p[j].id){
        cout << "Team:" << p[j].team << " name:" << p[j].name;
        cout << " id:" << p[j].id << " phonenumber:" << p[j].phonenumber;
        cout << " position:" << p[j].position << " address:" << p[j].address;
        cout << " salary:" << p[j].salary << endl;
        break;
      }
    }

  }



}

bool SearchTeamName(vector <Team> &t, string s, int num){
  bool f = false;
  for (int i = 1;i <= num; i++){
    if (t[i].name == s){
      f = true;
      break;
    }
  }
  return f;
}
