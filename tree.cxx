#include "tree.h"

Tree_node::Tree_node(int key, double op1, double op2,
		     double (*ope)(double v1, double v2))
: m_left{nullptr}, m_right{nullptr}, m_parent{nullptr}, m_key{key},
  m_operand1{op1}, m_operand2{op2}, m_operation{ope}{}



void Tree_node::Insert_node(Tree_node*& node, int key, double op1,
			    double op2, double (*ope)(double v1, double v2)){

  Tree_node* y{nullptr};
  Tree_node* x{node};
  Tree_node* new_node{new Tree_node{key, op1, op2, ope}};

  while(x != nullptr){
    y = x;
    if(new_node->m_key < x->m_key)
      x = x->m_left;
    else
      x = x->m_right;
  }

  new_node->m_parent = y;
  if(y == nullptr)
    node = new_node;
  else if(new_node->m_key < y->m_key)
    y->m_left = new_node;
  else
    y->m_right = new_node;

}



Tree_node* Tree_node::Search_key(Tree_node* node, int key){
  if(node == nullptr || key == node->m_key)
    return node;
  if(node->m_key < key)
    return Search_key(node->m_right, key);
  else
    return Search_key(node->m_left, key);
  
}



Tree_node* Tree_node::Tree_min(Tree_node* node){

  while(node->m_left != nullptr)
    node = node->m_left;
  return node;

}



void Tree_node::Transplant_node(Tree_node*& node, Tree_node* old_node,
				Tree_node* new_node){

  if(old_node->m_parent == nullptr)
    node = new_node;
  else if(old_node == old_node->m_parent->m_left)
    old_node->m_parent->m_left = new_node;
  else
    old_node->m_parent->m_right = new_node;

  if(new_node != nullptr)
    new_node->m_parent = old_node->m_parent;
    
}



void Tree_node::Pop_node(Tree_node* node, Tree_node* del_node){

  if(del_node == nullptr)
    return;
  if(del_node->m_left == nullptr)
    Transplant_node(node, del_node, del_node->m_right);
  else if(del_node->m_right == nullptr)
    Transplant_node(node, del_node, del_node->m_left);
  else{
    Tree_node* y = Tree_min(del_node->m_right);
    if(y->m_parent != del_node){
      Transplant_node(node, y, y->m_right);
      y->m_right = del_node->m_right;
      y->m_right->m_parent = y;
    }
    Transplant_node(node, del_node, y);
    y->m_left = del_node->m_left;
    y->m_left->m_parent = y;
  }

}



void Tree_node::Tree_walk(Tree_node* node){

  if(node != nullptr){
    Tree_walk(node->m_left);
    std::cout << node->m_key << "  ";
    Tree_walk(node->m_right);
    return;
  }else
    return;

}
