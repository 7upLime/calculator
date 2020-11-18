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


bool Scanner::is_function(const std::string& token){
  
  for(const auto& function : FUNCTIONS) // defined in operations.h
    if(function.find(token) != std::string::npos)
      return true;
  //else
  return false;
  
}


bool Scanner::is_operator(const std::string& tok){

  for(const auto& op : SYMBOLS) // defined in operations.h
    if(tok == op)
      return true;
  // else
  return false;

}



bool Scanner::is_bracket(const std::string& tok){

  const static std::vector<std::string> bracks{"(", "[",
					       "{", "}", "]", ")"};

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
