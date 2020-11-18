#include "test.h"


bool test_tree(void){
  
  Tree_node* root{NULL};
  OPERATION opp{ADDITION};
  double x{1.2}, y{4.3};
  double (*operation)(double, double){(*OPERATIONS[opp])};

  root->Insert_node(root, 0, x, y, operation);
  root->Insert_node(root, 1, x, y, operation);
  root->Insert_node(root, 15, x, y, operation);
  root->Insert_node(root, -2, x, y, operation);
  root->Insert_node(root, 11, x, y, operation);
  root->Insert_node(root, -15, x, y, operation);
  root->Insert_node(root, -115, x, y, operation);
  
  root->Tree_walk(root);

  return 0;

}


bool test_object_size(Tree_node *node){
  std::cout << static_cast<int>(sizeof(*node)) << std::endl;
  return 0;
}



bool Test_Scanner(void){

  std::string filename{"abbecedario.txt"};
  Scanner SCANNER{filename};

  SCANNER.input_check();
  SCANNER.print_checked_input();
  SCANNER.find_tokens();
  SCANNER.print_found_tokens();

  return true;

}



void test_fileIO(void){

  return ;

}
