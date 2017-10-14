#include "cliu45_op.h"

double add(double a, double b){
  return a + b;
}

double subtract(double a, double b){
  return a - b;
}

double multiple(double a, double b){
  return a * b;
}

int mod(double a, double b){
  return (int(a) % int(b));
}

double divide(double a, double b){
  return a / b;
}

bool iszero(double a){
  if (a == 0)
    return true;
  else
    return false;
}

bool isinteger(double a){
  if (a == int(a))
    return true;
  else
    return false;
}
