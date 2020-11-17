#pragma once
#include <iostream>

class Tree_node{
 private:
  int m_key;
  Tree_node* m_left;
  Tree_node* m_right;
  Tree_node* m_parent;
  
  double m_operand1;
  double m_operand2;
  double (*m_operation)(double, double);

 public:
  Tree_node(int, double, double, double(*)(double, double));
  Tree_node* Search_key(Tree_node*, int);
  Tree_node* Tree_min(Tree_node*);
  void Insert_node(Tree_node*&, int, double, double,
		   double(*)(double, double));
  void Transplant_node(Tree_node*&, Tree_node*, Tree_node*);
  void Pop_node(Tree_node*, Tree_node*);  
  void Tree_walk(Tree_node*);
  
};
