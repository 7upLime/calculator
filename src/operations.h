#pragma once

#include <cmath>
#include <cassert>
/* #include <map> */
#include <vector>
#include <string>

/*   ok... now I know that all of this was pretty useless....
     This project was meant also to help me learn c++,
     so at first I didn't know that you can add methods in class definition
     without adding weight to your class object...
     Now.. I could rewrite this and have it cleaner...
     but I kinda like its tangle... I like function pointer syntax
     It's more of a C-stylish implementation (???)*/



/* Here I define prototypes for each operation
   In order for the Tree_node class to access it,
   I firstly created an enum class holding operations and total n. of those
   The next structure is an array of pointer indexable by the 
   relative enum var, since operations defined in enum and arr have same order*/


double addition(double val1, double val2);
double subtraction(double val1, double val2);
double multiplication(double val1, double val2);
double division(double val1, double val2);
double pow(double val1, double val2);
double sqrt(double val1, double val2);
double sin(double val1, double val2);
double cos(double val1, double val2);
double tan(double val1, double val2);


enum OPERATION{
	       ////////////////////     Basic Operations
	       ADDITION,
	       SUBTRACTION,
	       MULTIPLICATION,
	       DIVISION,
	       
	       ////////////////////     power functions
	       POW,
	       SQRT,
	       
	       ////////////////////     trigonometric functions
	       SIN,
	       COS,
	       TAN,

	       NUM_OF_OPERATIONS
};


static double (*OPERATIONS[NUM_OF_OPERATIONS])(double, double) = {

							   addition,
							   subtraction,
							   multiplication,
							   division,
							   pow,
							   sqrt,
							   sin,
							   cos,
							   tan,
							   
};

/* 
   Some poor solution.. 
   I make use of those in identifiers.cxx
   The main issue was to verify if a token is a function
   and if a partial token is a function...
   with the same function...
*/
static std::vector<std::string> SYMBOLS{"+","-","*","/","^"};
static std::vector<std::string> FUNCTIONS{"sin","cos","tan","sqrt"};
