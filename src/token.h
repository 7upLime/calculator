#pragma once

#include <string>


enum TYPES{
	   NUM,
	   UNARY_OPERATOR,
	   BINARY_OPERATOR,
	   OPEN_BRACKET,
	   CLOSED_BRACKET,
	   END_TOK
};


struct TOKEN{

  std::string token;
  TYPES type;
  
};
