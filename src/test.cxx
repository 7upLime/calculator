#include "test.h"

bool Test_Scanner(void){

  std::string filename{"abbecedario.txt"};
  Scanner scanner{filename};

  scanner.input_check();
  scanner.find_tokens();
  scanner.print_found_tokens();

  return true;

}
