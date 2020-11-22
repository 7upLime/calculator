#pragma once

#include "token.h"

struct Tree_node{

  Tree_node* parent;
  Tree_node* right;
  Tree_node* left;

  int key;
  std::string token;
  TYPES type;

};
