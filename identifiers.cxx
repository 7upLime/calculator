#include "scanner.h"


bool Scanner::is_digit(const std::string& tok){

  bool static already_decimal;

  for(const auto t : tok){
    if(!(std::isdigit(t))){
      if(t == '.' && !already_decimal){
	already_decimal = true;
	continue;
      }else
	return false;
    }
  }

  return true;
}


bool Scanner::is_function(const std::string& token){

  const static std::vector<std::string> functions{"sin", "cos", "tan",
						  "sqrt"};

  for(const auto& function : functions)
    if(token == function)
      return true;

  //else
  return false;
  
}



bool Scanner::is_operator(const std::string& tok){

  const static std::vector<std::string> operators{"+", "-", "*", "/", "^"};

  for(const auto& op : operators)
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
