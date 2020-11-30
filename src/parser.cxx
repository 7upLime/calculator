#include "parser.h"

// more handy..
Parser::Parser(Scanner& scanner){

  auto begin{&(scanner.TOKENS[0])};
  auto end{&(scanner.TOKENS[0]) + sizeof(scanner.TOKENS)};

  for(auto ptr{begin}; ptr != end; ptr++){
    TOKENS.push_back(ptr);
    if(ptr->type == END_TOK)
      break;
  }

    
#ifdef DEBUG_V
  for(const auto tok : TOKENS)
    std::cout << "( " << tok->type << ", " << tok->token << " )\n";
#endif
}


bool Parser::syntax_check(void){

  int index{0}, size{static_cast<int>(TOKENS.size())};
  int brackets{0};

  while(TOKENS[index]->type != END_TOK){
    if(!check_current_token(TOKENS[index], TOKENS[index+1], brackets)){
      std::cout << "Invalid syntax" << std::endl;
      exit(EXIT_FAILURE);
    }
    index ++;
  }
  if(brackets != 0){
    SYNTAX_ERROR("Invalid syntax");
  }
  
#ifdef DEBUG
  std::cout << "Syntax check passed" << std::endl;
#endif
  return true;
  
}


bool Parser::check_current_token(TOKEN* current, TOKEN* next, int &brackets){

  // is there a more elegant solution to do this?

  switch(current->type){
  case NUM:
    if(next->type == CLOSED_BRACKET)
      return true;
    else if(next->type == BINARY_OPERATOR)
      return true;
    else if(next->type == END_TOK)
      return true;
    else
      return false;
    
  case BINARY_OPERATOR:
    if(next->type == NUM || next->type == UNARY_OPERATOR)
      return true;
    else if(next->type == OPEN_BRACKET)
      return true;
    else
      return false;
    
  case UNARY_OPERATOR:
    if(next->type != OPEN_BRACKET)
      return false;
    else
      return true;
    
  case OPEN_BRACKET:
    brackets += 1;
    if(next->type == BINARY_OPERATOR)
      return false;
    else if(next->type == CLOSED_BRACKET)
      return false;
    else if(next->type == END_TOK)
      return false;
    else
      return true;
    
  case CLOSED_BRACKET:
    brackets -= 1;
    if(next->type == UNARY_OPERATOR || next->type == NUM)
      return false;
    else
      return true;

  case END_TOK:
    return true;
    
  default:
    SYNTAX_ERROR("Unrecognized token");
    return true;
  }

}


Tree_node* Parser::pack_tree_node(TOKEN& tok, int key){
  /*
    Cause only NUMS and OPERATIONS are valid tree_nodes
   */
  double (*operation)(double, double);

  switch(tok.type){
  case NUM:
    operation = nullptr;
    break;
  case UNARY_OPERATOR:
    operation = assign_operation(tok);
    break;
  case BINARY_OPERATOR:
    operation = assign_operation(tok);
    break;
  default:
    SYNTAX_ERROR("Error while packing token");
  }

  Tree_node* node{new Tree_node{nullptr, nullptr, nullptr,
				  key, tok.token, tok.type, operation}};
  return node;

}


// operation ---->  double(*operation)(double, double)
operation Parser::assign_operation(TOKEN& tok){

  operation op{nullptr};
  auto begin{OPERATIONS.begin()};
  auto end{OPERATIONS.end()};

  if(tok.type == BINARY_OPERATOR){
    end = OPERATIONS.lower_bound("aa");
  }else if(tok.type == UNARY_OPERATOR){
    begin = OPERATIONS.upper_bound("aa");
  }else{
    SYNTAX_ERROR("Error while assigning operation to token");
  }

  for(auto ptr{begin}; ptr != end; ptr++){
    if(tok.token == ptr->first)
      return ptr->second;
  }
  
  SYNTAX_ERROR("Error while assigning operation to token");
  exit(EXIT_FAILURE);
  
}



Tree_node* Parser::build_subtree(Tree_node*& last_parent, int index){

  /*
    OK.. this is ''''ed up..
    The algorithm is basically:
    
    0.      // for every token in TOKENS:
    1. if(token already burnt)
    2.    skip
    3. if(eligible token)
    4.   populate_node() || error()
    5. if(OPEN_BRACKET)
    6.   recursion()
    7. if(next_token == CLOSED_BRACKET || END_TOK)
    8.   return last_seen_binary_operator
    9. token = next_token

   */

				// cause otherwise I have no clue on how to
				// call this function
  static Tree_node* last_child{nullptr};
  

  while(true){

    if(TOKENS[index] == nullptr){
      index++;
      continue;
    }
    

    if(TOKENS[index]->type == /*NUM*/ NUM){
      last_child = pack_tree_node(*TOKENS[index], 0);
      if(populate_node(last_parent, last_child))
	burn_token(index);
      else{
	SYNTAX_ERROR("Error while building tree");
      }
    
    }else if(TOKENS[index]->type == /* UNARY */ UNARY_OPERATOR){
      last_child = pack_tree_node(*TOKENS[index], 0);
      if(populate_node(last_parent, last_child))
	burn_token(index);
      else{
        SYNTAX_ERROR("Error while building tree");
      }
      
    }else if(TOKENS[index]->type == /*BINARY*/ BINARY_OPERATOR){
      last_parent = pack_tree_node(*TOKENS[index], 0);
      if(populate_node(last_child, last_parent))
	burn_token(index);
      else{
	SYNTAX_ERROR("Error while building tree");
      }

      
      
    }else if(TOKENS[index]->type == /*BRACKET*/ OPEN_BRACKET){
      if(populate_node(last_parent, build_subtree(last_parent, index)))
	burn_token(index);
      else{
	SYNTAX_ERROR("Error while building tree");
      }
    }




    if(TOKENS[index+1]->type == CLOSED_BRACKET ||
       TOKENS[index+1]->type == END_TOK){
      burn_token(index+1);
      return last_parent;
    }


    index++;

  }
  
}



void Parser::burn_token(int index){
  TOKENS[index] = nullptr;
}



bool Parser::populate_node(Tree_node* last, Tree_node* current){

  if(last == nullptr){
    return true;
  }

  if(current->token.type == BINARY_OPERATOR){
    if(last->parent == nullptr){
      last->parent = current;
      return true;
    }else{
      SYNTAX_ERROR("Error while populating node");
    }
  }else{
    if(last->left == nullptr){
      last->left = current;
      return true;
    }else if(last->right == nullptr){
      last->right = current;
      return true;
    }else{
      SYNTAX_ERROR("Error while populating node");
    }
  }

}


void Parser::build_tree(void){
  int zero{0};
  build_subtree(m_root_node, zero);
}


#ifdef DEBUG
void Parser::print_tree(Tree_node* node){}
#endif
