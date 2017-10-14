#include<iostream>
#include "cliu45_team.h"
#include "cliu45_player.h"
#include "cliu45_agency.h"
#include<string>
#include<vector>
using namespace std;
vector <Player> MLBPlayer;
vector <Team> MLBTeam;
int playernum = 0;
int teamnum = 0;
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
    if (!SearchTeamName(MLBTeam, s1, teamnum)){
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
      if (SearchPlayerId(MLBPlayer, ind, playernum)){
        cout << "The ID is existed. You must be somewhere wrong. Registration isn't allowed" << endl;
      }
      else {
        string s3;
        cout << "Please input the phone number of the player " << i << ":";
        cin >> s3;
        //int len = s3.length();
        //s3 = s3.substr(0, len - 1);
        if (SearchPlayerPhone(MLBPlayer, s3, playernum)){
          cout << "Existed phone number. Registration isn't allowed" << endl;
        }
        else {
          playernum++;
          Player *p = new Player();
          MLBPlayer.push_back(*p);
          MLBPlayer[playernum].team = s1;
          MLBPlayer[playernum].name = s2;
          MLBPlayer[playernum].id = ind;
          MLBPlayer[playernum].phonenumber = s3;
          cout << "Please input the position of the player " << i << ":";
          string t;
          cin >> t;
          //int len = t.length();
          //t = t.substr(0, len - 1);
          MLBPlayer[playernum].position = t;
          cout << "Please input the address of the player " << i << ":";

          cin >> t;
          //len = t.length();
          //t = t.substr(0, len - 1);
          MLBPlayer[playernum].address = t;
          double d;
          cout << "Please input the salary of the player " << i << ":";
          cin >> d;
          MLBPlayer[playernum].salary = d;
          //cout << playernum << endl;
          //cout << "Team:" << MLB[playernum].team << " name:" << MLB[playernum].name;
          //cout << "id:" << MLB[playernum].id << " phonenumber:" << MLB[playernum].phonenumber;
          //cout << " position:" << MLB[playernum].position << " address:" << MLB[playernum].address;
          //cout << " salary:" << MLB[playernum].salary << endl;
          for (int j = 1;j <= teamnum; j++){
            if (MLBTeam[j].name == s1){
              MLBTeam[j].numofplayers++;
              MLBTeam[j].playerlist.push_back(ind);
              break;
            }
          }
          //cout << p1 -> member.index << endl;
          //cout << p1 -> city << endl;

            //cout << (&(p1 -> member)) -> next -> index << endl;

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
  if (SearchTeamName(MLBTeam, s1, teamnum) == true){
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
    Team *p = new Team();
    teamnum++;
    MLBTeam.push_back(*p);
    MLBTeam[teamnum].name = s1;
    MLBTeam[teamnum].city = s2;
    MLBTeam[teamnum].playerlist.reserve(1000);
    MLBTeam[teamnum].playerlist.push_back(0);
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
  if (!SearchTeamName(MLBTeam, s1, teamnum))  {
    cout << "Team name isn't existed." << endl;
  }
  else {
    for (int i = 1;i <= teamnum; i++){
      if (MLBTeam[i].name == s1){
        MLBTeam[i].DisplayTeam(MLBPlayer, playernum);
        break;
      }
    }
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
    FindWithName(MLBPlayer, s1, playernum);
  }
  else if (num == 2){
    cout << "Input the id:";
    int ind;
    cin >> ind;
    FindWithId(MLBPlayer, ind, playernum);
  }
  else if (num == 3){
    cout << "Input phone number:";
    string s2;
    cin >> s2;
    //int len = s2.length();
    //s2 = s2.substr(0, len - 1);
    FindWithPhone(MLBPlayer, s2, playernum);
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
    SortWithName(MLBPlayer, playernum, s1);
  }
  else if (num == 2){
    SortWithId(MLBPlayer, playernum, s1);
  }
  else if (num == 3){
    SortWithSalary(MLBPlayer, playernum, s1);
  }


}
int main(){
  int n = 0;
  MLBPlayer.reserve(1000);
  MLBTeam.reserve(1000);
  Player *p = new Player();
  MLBPlayer.push_back(*p);
  Team *t = new Team();
  MLBTeam.push_back(*t);
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
  delete p;
  delete t;
  return 0;
}
