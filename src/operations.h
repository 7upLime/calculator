#pragma once

#include <cmath>
#include <cassert>
#include <array>
#include <string>
#include <map>

#include "token.h"

/*
  Here are the prototypes for the math functions that I'll use
  and a structure /mapping/ the strings I use to identify operations
  to their relative implementation, as a function pointer
  The strings are used in identifiers.h
*/
double addition(double val1, double val2);
double subtraction(double val1, double val2);
double multiplication(double val1, double val2);
double division(double val1, double val2);
double pow(double val1, double val2);
double sin(double val1, double val2);
double cos(double val1, double val2);
double tan(double val1, double val2);


typedef double (*operation)(double, double);
static std::map<std::string, operation> OPERATIONS{
						   {"+", addition},
						   {"-", subtraction},
						   {"*", multiplication},
						   {"/", division},
						   {"^", pow},
						   {"sin",sin},
						   {"cos",cos},
						   {"tan",tan},
};
