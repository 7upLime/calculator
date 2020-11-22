#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "parser.h"

#define DEBUG


/*
  This class is mostly an input checker..
  The work is done by input_check() first &then by find_tokens()
  The results are stored inside TOKENS & CHECKED_INPUT
*/

class Scanner{
 private:
  std::string m_filename;
  std::string INPUT;
  std::string CHECKED_INPUT;
  std::vector<TOKEN> TOKENS;

  
  // Token check
  static bool is_function(const std::string&);
  static bool is_digit(const std::string&);
  static bool is_operator(const std::string&);
  static bool is_bracket(const std::string&);

  // Single char check
  bool is_relevant(const char);
  bool is_alnum(const char);
  bool is_space(const char);
  bool is_notvalid(const char);
  bool is_invalidchar(const char);

  // TOKEN utils
  bool check_token(const std::string&); // checks token name validity
  TOKEN categorize_token(std::string&); // packs TOKEN struct


  friend class Parser;		// it passes all tokens to Parser

public:
  Scanner(std::string& filename) : m_filename{filename} {}

  
  void input_check(void);	// FIRST STEP
  void find_tokens(void);	// SECOND STEP


  
#ifdef DEBUG
  void print_checked_input(void);
  void print_found_tokens(void);
  void print_token_role(const std::string&);  
#endif

};
