#include "cliu45_player.h"
#include<iostream>
using namespace std;


bool SearchPlayerId(vector <Player> &p, int ind, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (p[i].id == ind){
      f = true;
    }
  }
  return f;
}

bool SearchPlayerPhone(vector <Player> &p, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (p[i].phonenumber == s){
      f = true;
    }
  }
  return f;
}

void FindWithName(vector <Player> &p, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (p[i].name == s){
      cout << "Team:" << p[i].team << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void FindWithId(vector <Player> &p, int ind, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (p[i].id == ind){
      cout << "Team:" << p[i].team << " name:" << p[i].name << " phonenumber:" << p[i].phonenumber;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void FindWithPhone(vector <Player> &p, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (p[i].phonenumber == s){
      cout << "Team:" << p[i].team << " name:" << p[i].name << " id:" << p[i].id;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void SortWithName(vector <Player> &p, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (p[i].name > p[j].name) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << p[i].team << " name:" << p[i].name;
      cout << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((p[i].name > p[j].name)&&(p[i].team == s)&&(p[j].team == s)) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (p[i].team == s){
        cout << "Team:" << p[i].team << " name:" << p[i].name;
        cout << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
        cout << " position:" << p[i].position << " address:" << p[i].address;
        cout << " salary:" << p[i].salary << endl;
      }
    }
  }
}

void SortWithId(vector <Player> &p, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (p[i].id > p[j].id) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << p[i].team << " name:" << p[i].name;
      cout << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((p[i].id > p[j].id)&&(p[i].team == s)&&(p[j].team == s)) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (p[i].team == s){
        cout << "Team:" << p[i].team << " name:" << p[i].name;
        cout << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
        cout << " position:" << p[i].position << " address:" << p[i].address;
        cout << " salary:" << p[i].salary << endl;
      }
    }
  }
}

void SortWithSalary(vector <Player> &p, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (p[i].salary < p[j].salary) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << p[i].team << " name:" << p[i].name;
      cout << " id:" << p[i].id<< " phonenumber:" << p[i].phonenumber;
      cout << " position:" << p[i].position << " address:" << p[i].address;
      cout << " salary:" << p[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((p[i].salary < p[j].salary)&&(p[i].team == s)&&(p[j].team == s)) {
          Player x;
          x = p[i];p[i] = p[j];p[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (p[i].team == s){
        cout << "Team:" << p[i].team << " name:" << p[i].name;
        cout << " id:" << p[i].id << " phonenumber:" << p[i].phonenumber;
        cout << " position:" << p[i].position << " address:" << p[i].address;
        cout << " salary:" << p[i].salary << endl;
      }
    }
  }
}
