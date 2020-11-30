#pragma once


#include "token.h"
#include "tree.h"
#include "scanner.h"
#include "operations.h"


#define DEBUG
#define DEBUG_V

/*
  Because with a normal function, the compiler
  would throw warnings at each function reaching end-flow
  without returning something
  But......
  without brackets in else statements..
  this produced some really nasty ******' bugs
  that neither the compiler (for obvious reasons..) nor the debugger
  could spot. so that's why preproc macros are the devil..
*/
#define SYNTAX_ERROR(msg)			\
  std::cout << msg << std::endl;		\
  exit(EXIT_FAILURE);


/*
  because otherwise...
  assign_operation() would be a mess
*/
typedef double (*operation)(double, double);

// Forwards:
class Scanner;			// from scanner.h
struct TOKEN;			// from token.h
struct Tree_node;		// from tree.h

class Parser{
private:
  Tree_node* m_root_node{nullptr};
  std::vector<TOKEN*> TOKENS;

public:
  // when object is created, TOKENS are passed from scanner to parser
  Parser(Scanner&);

  // these are /syntax check/ functions
  /** currently the syntax check is performed in the TOKENS queue **/
  bool syntax_check(void);
  bool check_current_token(TOKEN*, TOKEN*, int&);

  // well.. it builds the tree..
  void build_tree(void);
  Tree_node* build_subtree(Tree_node*&, int);
#ifdef DEBUG
  void print_tree(Tree_node*);
#endif
  void burn_token(int);
  bool populate_node(Tree_node*,Tree_node*);

  // These are /node/ functions
  Tree_node* pack_tree_node(TOKEN&, int);
  operation assign_operation(TOKEN&);

};
