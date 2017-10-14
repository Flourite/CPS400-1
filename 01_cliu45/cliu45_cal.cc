#include <iostream>
#include "cliu45_op.h"
using namespace std;

int main(){
  double x, y;
  char oper, yesorno;
  bool flag = true;
  while (flag) {
    cout << "Enter your operator:";
    cin >> oper;
    while ((oper != '+')&&(oper != '-')&&(oper != '/')&&(oper != '*')&&(oper != '%')){
      cout << "Operator not found, please input another:";
      cin >> oper;
    }
    cout << "Enter the first operand:";
    cin >> x;
    if (oper == '%'){
      while (isinteger(x) == false){
        cout << "Must be an integer, please input again:";
        cin >> x;
      }
    }
    cout << "Enter the second operand:";
    cin >> y;
    if (oper == '%'){
      while (isinteger(y) == false){
        cout << "Must be an integer, please input again:";
        cin >> y;
      }
    }
    if (oper == '/'){
      while (iszero(y) == true){
        cout << "The divisor cannot be zero, please input again:";
        cin >> y;
      }
    }
    cout << "The result of calcuation is ";
    switch (oper) {
      case '+':
        cout << add(x, y) << endl;
        break;
      case '-':
        cout << subtract(x, y) << endl;
        break;
      case '*':
        cout << multiple(x, y) << endl;
        break;
      case '/':
        cout << divide(x, y) << endl;
        break;
      case '%':
        cout << mod(x, y) << endl;
        break;
    }
    cout << "Do you want to do more calculation? (y/n)";
    cin >> yesorno;
    while ((yesorno != 'n')&&(yesorno != 'y')){
      cout << "I dont know what you mean, please type it again(y/n)";
      cin >> yesorno;
    }
    if (yesorno == 'n'){
      cout << "Thank you and goodbye" << endl;
      break;
    }
  }
  return 0;
}
