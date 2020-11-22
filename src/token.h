#pragma once

#include <string>


enum TYPES{
	   NUM,
	   UNARY_OPERATOR,
	   BINARY_OPERATOR,
	   BRACKET,
};


struct TOKEN{

  std::string token;
  TYPES type;
  
};
