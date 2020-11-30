#include "scanner.h"
#include "operations.h"


bool Scanner::is_digit(const std::string& tok){

  int dots{0};			// its initialized with 0 at 
                                // each function call
  for(const auto t : tok){
    if(!(std::isdigit(t))){
      if(t == '.' && dots < 2){	// zero, one, or more dots
        dots++;
	continue;
      }else			// more than one dot
	dots = 0;
	return false;
    }
  }

  return true;
}

/*
  OPERATION::FUNCTIONS is not very clear..
  that separates the names of the unary_operator from those of 
  the binary_operators in OPERATION_NAMES array inside "operations.h"
*/

bool Scanner::is_function(const std::string& token){

  // these are defined in operations.h
  auto begin{OPERATIONS.upper_bound("aa")};
  // this because every UNARY_OPERATOR is a string with more than two chars
  // and every BINARY_OP is a one char string
  auto end{OPERATIONS.end()};
  
  for(auto ptr{begin}; ptr != end; ptr++)
    if(ptr->first.find(token) != std::string::npos)
      return true;
  //else
  return false;
  
}


bool Scanner::is_operator(const std::string& tok){

  // defined in operations.h
  auto begin{OPERATIONS.begin()};
  auto end{OPERATIONS.lower_bound("aa")};
  // this because every UNARY_OPERATOR is a string with more than two chars
  // and every BINARY_OP is a one char string

  for(auto ptr{begin}; ptr != end; ptr++)
    if(tok == ptr->first)
      return true;
  // else
  return false;

}


bool Scanner::is_bracket(const std::string& tok){
  return is_open_bracket(tok) || is_close_bracket(tok);
}


bool Scanner::is_open_bracket(const std::string& tok){

  const static std::vector<std::string> bracks{"(", "[", "{"};

  for(const auto& b : bracks)
    if(tok == b)
      return true;

  // else
  return false;

}


bool Scanner::is_close_bracket(const std::string& tok){

  const static std::vector<std::string> bracks{")", "]", "}"};

  for(const auto& b : bracks)
    if(tok == b)
      return true;

  // else
  return false;

}



bool Scanner::is_alnum(const char ch){
  return std::isalnum(ch);
}


bool Scanner::is_space(const char ch){
  
  return std::isspace(ch);
  
}


bool Scanner::is_notvalid(const char ch){
  
  if(std::iscntrl(ch) && !(std::isspace(ch)))
    return true;
  else
    return false;

}


bool Scanner::is_invalidchar(const char ch){

  const static std::vector<char> invalids{'$','%','&','#',';',':',
					  '`', '|','~','@','\'','\'',
					  '?', '\\', '<', '>'};

  for(const auto inv : invalids)
    if(ch == inv)
      return true;

  return false;

}

bool Scanner::is_relevant(const char ch){

  if(is_alnum(ch) || ch == '.')
    return true;
  else if(is_operator(std::string(1, ch)))
    return true;
  else if(is_bracket(std::string(1, ch)))
    return true;
  else
    return false;

}
