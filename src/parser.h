#pragma once

#include <map>

#include "token.h"
#include "tree.h"
#include "scanner.h"

// Forwards:
class Scanner;			// from scanner.h
class Tree_node;		// from tree.h
struct TOKEN;

class Parser{
private:
  Tree_node* m_root_node{NULL};
  std::vector<TOKEN> TOKENS;

public:
  Parser(Scanner&);
  
  void feed_tokens(Scanner&);
  bool syntax_check(void);

};
