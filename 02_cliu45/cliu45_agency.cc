#include<iostream>
#include "cliu45_agency.h"
#include<string>
using namespace std;
player MLB[50];
team *teamhead = new team;
int playernum = 0;
void AddPlayer(){
  int num = 0;
  string s1;
  cout << "Please input the number of players you want to add:";
  cin >> num;
  for (int i = 1;i <= num;i++){
    cout << "Please input the team name of player " << i <<":";
    cin >> s1;
    //int len = s1.length();
    //s1 = s1.substr(0, len - 1);
    if (!SearchTeamName(teamhead, s1)){
      cout << "The team doen't exist. You should add the team together with this player first" << endl;
    }
    else {
      string s2;
      cout << "Please input the name of the player " << i <<":";
      cin >> s2;
      //int len = s2.length();
      //s2 = s2.substr(0, len - 1);
      cout << "Please input the id of the player " << i <<":";
      int ind;
      cin >> ind;
      if (SearchPlayerId(MLB, ind, playernum)){
        cout << "The ID is existed. You must be somewhere wrong. Registration isn't allowed" << endl;
      }
      else {
        string s3;
        cout << "Please input the phone number of the player " << i << ":";
        cin >> s3;
        //int len = s3.length();
        //s3 = s3.substr(0, len - 1);
        if (SearchPlayerPhone(MLB, s3, playernum)){
          cout << "Existed phone number. Registration isn't allowed" << endl;
        }
        else {
          playernum++;
          MLB[playernum].team = s1;
          MLB[playernum].name = s2;
          MLB[playernum].id = ind;
          MLB[playernum].phonenumber = s3;
          cout << "Please input the position of the player " << i << ":";
          string t;
          cin >> t;
          //int len = t.length();
          //t = t.substr(0, len - 1);
          MLB[playernum].position = t;
          cout << "Please input the address of the player " << i << ":";

          cin >> t;
          //len = t.length();
          //t = t.substr(0, len - 1);
          MLB[playernum].address = t;
          double d;
          cout << "Please input the salary of the player " << i << ":";
          cin >> d;
          MLB[playernum].salary = d;
          //cout << playernum << endl;
          //cout << "Team:" << MLB[playernum].team << " name:" << MLB[playernum].name;
          //cout << "id:" << MLB[playernum].id << " phonenumber:" << MLB[playernum].phonenumber;
          //cout << " position:" << MLB[playernum].position << " address:" << MLB[playernum].address;
          //cout << " salary:" << MLB[playernum].salary << endl;
          team *p1;
          p1 = teamhead;
          bool flag = false;
          while (p1 != NULL){
            if (p1 -> name == s1){
              flag = true;
              break;
            }
            else p1 = p1 -> next;
          }
          //cout << p1 -> member.index << endl;
          //cout << p1 -> city << endl;
          if (flag) {
            playerlist *q1 = new playerlist;
            q1 = &(p1 -> member);
            playerlist *q2 = new playerlist;
            q2 -> next = NULL;
            q2 -> index = playernum;
            q2 -> id = MLB[playernum].id;
            while (q1 -> next != NULL){
              q1 = q1 -> next;
            }
            q1 -> next = q2;
            p1 -> numofplayers++;
            //cout << (&(p1 -> member)) -> next -> index << endl;
          }
        }
      }
    }
  }
}

void AddTeam(){
  cout << "Please input the team name:";
  string s1;
  cin >> s1;
  //cout << s1 << endl;
  //int len = s1.length();
  //cout << len << endl;
  //s1 = s1.substr(0, len - 1);
  //cout << s1 << endl;
  if (SearchTeamName(teamhead, s1)){
    cout << "The team name is existed! Team registration isn't allowed" << endl;
  }
  else {
    string s2;
    cout << "Input the city:";
    cin >> s2;
    //int len = s1.length();
    //s1 = s1.substr(0, len - 1);
    //cout << s1 << endl;
    //cout << s2 << endl;
    team *p1;
    p1 = teamhead;
    //cout << p1 -> name << endl;
    while (p1 -> next != NULL){
      p1 = p1 -> next;
    }
    team *p2 = new team;
    p2 -> name = s1;
    p2 -> city = s2;
    p2 -> numofplayers = 0;
    p2 -> next = NULL;
    //cout << p2 -> name << endl;
    playerlist *q1 = new playerlist;
    q1 -> next = NULL;
    p2 -> member = *q1;
    p1 -> next = p2;
    //cout << teamhead -> next -> name << endl;
    //cout << teamhead -> next -> city << endl;
  }
}

void Display(){
  cout << "Input the team name you want to display:";
  string s1;
  cin >> s1;
  //int len = s1.length();
  //s1 = s1.substr(0, len - 1);
  if (!SearchTeamName(teamhead, s1))  {
    cout << "Team name isn't existed." << endl;
  }
  else {
    //int a[50];
    DisplayTeam(teamhead, s1, MLB);
  }
}

void FindPlayer(){
  cout << "If you want to find player with name, please input 1" << endl;
  cout << "If you want to find the player with id, please input 2" << endl;
  cout << "If you want to find the player with phone, please input 3" << endl;
  int num;
  cout << "Please input:";
  cin >> num;
  if (num == 1){
    cout << "Input the name:";
    string s1;
    cin >> s1;
    //int len = s1.length();
    //s1 = s1.substr(0, len - 1);
    FindWithName(MLB, s1, playernum);
  }
  else if (num == 2){
    cout << "Input the id:";
    int ind;
    cin >> ind;
    FindWithId(MLB, ind, playernum);
  }
  else if (num == 3){
    cout << "Input phone number:";
    string s2;
    cin >> s2;
    //int len = s2.length();
    //s2 = s2.substr(0, len - 1);
    FindWithPhone(MLB, s2, playernum);
  }
  else {
    cout << "I don't know what do you mean?" << endl;
  }
}

void SortPlayer(){
  cout << "If you want to sort with name, please input 1" << endl;
  cout << "If you want to sort with ID, please input 2" << endl;
  cout << "If you want to sort with salary, please input 3" << endl;
  cout << "Which will you choose?:";
  int num;
  cin >> num;
  cout << "If you want to sort by a team, please input 1, for sort all the players input 0:";
  int num1;
  cin >> num1;
  string s1 = "";
  if (num1 == 1){
    cout << "Input the team name:";
    cin >> s1;
  }
  if (num == 1){
    SortWithName(MLB, playernum, s1);
  }
  else if (num == 2){
    SortWithId(MLB, playernum, s1);
  }
  else if (num == 3){
    SortWithSalary(MLB, playernum, s1);
  }

  ChangeIndex(teamhead, playernum, MLB);

}
int main(){
  int n = 0;
  teamhead -> next = NULL;
  playerlist *playerhead = new playerlist;
  playerhead -> next = NULL;
  teamhead -> member = *playerhead;
  cout << "Start. Now there are no players and teams. You should add players and teams first" << endl;
  while (true) {
    cout << "If you want to add players, please input 1." << endl;
    cout << "If you want to add a team, please input 2." << endl;
    cout << "If you want to display the players in one team, please input 3." << endl;
    cout << "If you want to find the players, please input 4." << endl;
    cout << "If you want to sort the players with id, please input 5." << endl;
    cout << "If you want to terminate the program, please input 0." << endl;
    cout << "So what do you want to do now?";
    cin >> n;
    if (n == 1){
      AddPlayer();
    }
    else if (n == 2){
      AddTeam();
    }
    else if (n == 3){
      Display();
    }
    else if (n == 4){
      FindPlayer();
    }
    else if (n == 5){
      SortPlayer();
    }
    else if (n == 0){
      cout << "Thank you and goodbye." << endl;
      break;
    }
    else{
      cout << "What do you mean?" << endl;
    }
  }
  team *p1, *p2;
  p1 = teamhead;
  p2 = p1;
  while (p2 != NULL){
    playerlist *p3, *p4;
    p3 = &(p2 -> member);
    p4 = p3 -> next;

    while (p4 != NULL){

      p3 = p4 -> next;
      if (p4 != NULL){
        delete p4;
      }
      p4 = p3;
    }

    p1 = p2 -> next;
    if (p2 != NULL){
      delete p2;
    }
    p2 = p1;
  }

  return 0;
}
