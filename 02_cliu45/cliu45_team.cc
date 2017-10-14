#include "cliu45_team.h"
#include "cliu45_player.h"
#include<string>
#include<iostream>
using namespace std;
void DisplayTeam(team *t, string s, player *m){
  team *p1;

  p1 = t;
  bool f = false;
  while (p1 != NULL){
    if (p1 -> name == s){
      f = true;
      break;
    }
    p1 = p1 -> next;
  }
  if (f){
    playerlist *q1 = new playerlist;
    *q1 = p1 -> member;
    playerlist *q2;
    q2 = q1;
    while (q2 != NULL){
      int ind;
      ind = q2 -> index;
      if (ind != 0){
        cout << "Team:" << m[ind].team << " name:" << m[ind].name;
        cout << " id:" << m[ind].id << " phonenumber:" << m[ind].phonenumber;
        cout << " position:" << m[ind].position << " address:" << m[ind].address;
        cout << " salary:" << m[ind].salary << " index:" << ind << endl;
      }
      q2 = q2 -> next;
    }
    delete q1;
  }

}

bool SearchTeamName(team *t, string s){
  team *p1;

  p1 = t;
  bool f = false;
  while (p1 != NULL){
    if (p1 -> name == s){
      f = true;
      break;
    }
    p1 = p1 -> next;
  }
  return f;
}

void ChangeIndex(team *t, int n, player *m){
  team *p1;
  string s;
  int num;
  for (int i = 1;i <=n; i++){
    p1 = t;
    s = m[i].team;
    while (p1 != NULL){
      if (p1 -> name == s){
        break;
      }
      p1 = p1 -> next;
    }
    playerlist *q1;
    q1 = &(p1 -> member);
    num = m[i].id;
    while (q1 != NULL){
      if (q1 -> id == num){
        break;
      }
      q1 = q1 -> next;
    }
    q1 -> index = i;
  }
}
