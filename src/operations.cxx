#include "operations.h"

double addition(double val1, double val2){
  return val1 + val2;
}

double subtraction(double val1, double val2){
  return val1 - val2;
}

double multiplication(double val1, double val2){
  return val1 * val2;
}

double division(double val1, double val2){
  assert(val2 != 0);
  return val1 / val2;
}

double pow(double val1, double val2){
  return std::pow(val1, val2);
}

double sin(double val1, double val2){
  return std::sin(val1);
}

double cos(double val1, double val2){
  return std::cos(val1);
}

double tan(double val1, double val2){
  return std::tan(val1);
}
