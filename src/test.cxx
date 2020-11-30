#include "test.h"

bool Test_Scanner(void){

  std::string filename{"abbecedario.txt"};
  Scanner scanner{filename};

  scanner.input_check();
  // scanner.print_checked_input();  #ifdef DEBUG
  scanner.find_tokens();
  // scanner.print_found_tokens();
  Parser parser{scanner};
  if(!parser.syntax_check()){
    std::cout << "[!!] syntax check not passed" << std::endl;
  }else
    parser.build_tree();

  return true;

}


void print_binary_operators(void){
  auto begin{OPERATIONS.begin()};
  // because every Unary_operator is a string with more than two chars
  // and every binary_op is a one char string
  auto end{OPERATIONS.lower_bound("aa")};
  
  for(auto ptr{begin}; ptr != end; ptr++)
    std::cout << ptr->first << std::endl;
}

void print_unary_operators(void){
  auto begin{OPERATIONS.upper_bound("aa")};
  // because every Unary_operator is a string with more than two chars
  // and every binary_op is a one char string
  auto end{OPERATIONS.end()};
  
  for(auto ptr{begin}; ptr != end; ptr++)
    std::cout << ptr->first << std::endl;
}
