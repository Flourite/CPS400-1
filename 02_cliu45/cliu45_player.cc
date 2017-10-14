#include "cliu45_player.h"
#include<iostream>
using namespace std;


bool SearchPlayerId(player *m, int ind, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (m[i].id == ind){
      f = true;
    }
  }
  return f;
}

bool SearchPlayerPhone(player *m, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (m[i].phonenumber == s){
      f = true;
    }
  }
  return f;
}

void FindWithName(player *m, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (m[i].name == s){
      cout << "Team:" << m[i].team << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void FindWithId(player *m, int ind, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (m[i].id == ind){
      cout << "Team:" << m[i].team << " name:" << m[i].name << " phonenumber:" << m[i].phonenumber;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void FindWithPhone(player *m, string s, int n){
  bool f = false;
  for (int i = 1;i <= n;i++){
    if (m[i].phonenumber == s){
      cout << "Team:" << m[i].team << " name:" << m[i].name << " id:" << m[i].id;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
      f = true;
    }
  }
  if (!f){
    cout << "Not Found." << endl;
  }
}

void SortWithName(player *m, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (m[i].name > m[j].name) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << m[i].team << " name:" << m[i].name;
      cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((m[i].name > m[j].name)&&(m[i].team == s)&&(m[j].team == s)) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (m[i].team == s){
        cout << "Team:" << m[i].team << " name:" << m[i].name;
        cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
        cout << " position:" << m[i].position << " address:" << m[i].address;
        cout << " salary:" << m[i].salary << endl;
      }
    }
  }
}

void SortWithId(player *m, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (m[i].id > m[j].id) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << m[i].team << " name:" << m[i].name;
      cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((m[i].id > m[j].id)&&(m[i].team == s)&&(m[j].team == s)) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (m[i].team == s){
        cout << "Team:" << m[i].team << " name:" << m[i].name;
        cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
        cout << " position:" << m[i].position << " address:" << m[i].address;
        cout << " salary:" << m[i].salary << endl;
      }
    }
  }
}

void SortWithSalary(player *m, int n, string s){
  if (s == ""){
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if (m[i].salary < m[j].salary) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      cout << "Team:" << m[i].team << " name:" << m[i].name;
      cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
      cout << " position:" << m[i].position << " address:" << m[i].address;
      cout << " salary:" << m[i].salary << endl;
    }
  }
  else {
    for (int i = 1;i <n;i++){
      for (int j = i + 1;j <= n;j++){
        if ((m[i].salary < m[j].salary)&&(m[i].team == s)&&(m[j].team == s)) {
          player x;
          x = m[i];m[i] = m[j];m[j] = x;
        }
      }
    }
    for (int i = 1;i <= n;i++){
      if (m[i].team == s){
        cout << "Team:" << m[i].team << " name:" << m[i].name;
        cout << " id:" << m[i].id << " phonenumber:" << m[i].phonenumber;
        cout << " position:" << m[i].position << " address:" << m[i].address;
        cout << " salary:" << m[i].salary << endl;
      }
    }
  }
}
