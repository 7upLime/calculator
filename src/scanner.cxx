#include "scanner.h"

void Scanner::input_check(){

  /*
    This is the first step in parsing input:
    It will read the INPUT member 
    and will store all the relevant chars inside CHECKED_INPUT
    quits at first invalid char found
    It returns in CHECKED_INPUT member of Scanner class
    a string with only valid chars, no spaces.
  */ 
  
  char ch;
  std::fstream file(m_filename, std::fstream::in);
  
  
  while(file >> std::noskipws >> ch){
    
    if(is_notvalid(ch) || is_invalidchar(ch)){
      std::cout << "[!!] Input error, exiting...." << std::endl;
      exit(EXIT_FAILURE);
      
    }else{
      if(is_relevant(ch))
	CHECKED_INPUT += ch;
    }
  }

  if(CHECKED_INPUT == ""){
    std::cout << "[!!] No input provided, exiting......\n";
    exit(EXIT_FAILURE);
  }
  
}



/*
  This is kind of repetitive, but otherwise check_token()
  would write to a variable many times in find_tokens,
  and also carry a pointer...
  a waste I think..
*/
TOKEN Scanner::categorize_token(std::string &token){

  if(is_function(token))
    return TOKEN{token,UNARY_OPERATOR};
  else if(is_operator(token))
    return TOKEN{token,BINARY_OPERATOR};
  else if(is_open_bracket(token))
    return TOKEN{token, OPEN_BRACKET};
  else if(is_close_bracket(token))
    return TOKEN{token, CLOSED_BRACKET};
  else
    return TOKEN{token,NUM};

}



void Scanner::find_tokens(void){
  
  /* 
     This will read the CHECKED_INPUT in a greedy way
     and will store found tokens inside the TOKENS member
  */

  int index{0};
  std::string buffer;
  TYPES type;
  TOKEN token;
  

  while(index < CHECKED_INPUT.length()){
    buffer += CHECKED_INPUT[index++];
    while(check_token(buffer)){
      buffer += CHECKED_INPUT[index]; // Kinda messy
      index++;			      // here it will always have one more
    }				      // that the valid token
    buffer.pop_back();
    token = categorize_token(buffer); // packs the struct
    TOKENS.push_back(token);
    index--;			// here we adjust the index
    buffer = "";		// otherwise will always miss a char
  }

  token = {"end", END_TOK};	// packs an END_TOKEN
  TOKENS.push_back(token);     // ends the TOKENS vector

#ifdef DEBUG
  std::cout << "[*] find_tokens() returned normally\n";
#endif
}



// functions here come from identifiers.cxx
bool Scanner::check_token(const std::string& buffer){

  if(is_open_bracket(buffer) || is_close_bracket(buffer))
    return true;
  else if(is_operator(buffer))
    return true;
  else if(is_function(buffer) || is_digit(buffer))
    return true;
  else
    return false;
    

}




#ifdef DEBUG
void Scanner::print_checked_input(void){
  std::cout << CHECKED_INPUT << std::endl;
}

void Scanner::print_found_tokens(){
  for(auto i : TOKENS){
    // std::cout << i << std::endl;
    print_token_role(i.token);
  }
}



void Scanner::print_token_role(const std::string& token){
  
  if(is_function(token))
    std::cout << "  - Function, " << token << std::endl;
  else if(is_operator(token))
    std::cout << "  - Operator, " << token << std::endl;
  else if(is_digit(token))
    std::cout << "  - Digit, " << token << std::endl;
  else if(is_open_bracket(token))
    std::cout << "  - Bracket,  " << token << std::endl;
  else{
    std::cout << "  [!!] Error while identifying token: ` "
	      << token << " ` exiting...\n";
    exit(EXIT_FAILURE);
  }
  
  return;

}

#endif
