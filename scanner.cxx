#include "scanner.h"

// void Scanner::print_token(const std::string& token){
  
//   if(is_function(token))
//     std::cout << "  - Function, " << token << std::endl;
//   else if(is_operator(token))
//     std::cout << "  - Operator, " << token << std::endl;
//   else if(is_digit(token))
//     std::cout << "  - Digit, " << token << std::endl;
//   else if(is_bracket(token))
//     std::cout << "  - Bracket,  " << token << std::endl;
//   else{
//     std::cout << "  [!!] Error while identifying token: ` "
// 	      << token << " ` exiting...\n";
//     exit(EXIT_FAILURE);
//   }
  
//   return;

// }




void Scanner::pre_check(){

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

  if(CHECKED_INPUT == "")
    std::cout << "[!!] No input provided, exiting......\n";
    exit(EXIT_FAILURE);
  
}


#ifdef DEBUG
void Scanner::print_checked_input(void){
  std::cout << CHECKED_INPUT << std::endl;
}
#endif
