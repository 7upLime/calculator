#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <functional>

#define DEBUG

class Scanner{
 private:
  std::string m_filename;
  std::string INPUT;
  std::string CHECKED_INPUT;
  std::vector<std::string> TOKENS;
  
 public:

  Scanner(std::string& filename) : m_filename{filename} {}

  // Token check
  bool is_function(const std::string&);
  bool is_digit(const std::string&);
  bool is_operator(const std::string&);
  bool is_bracket(const std::string&);

  // Single char check
  bool is_relevant(const char);
  bool is_alnum(const char);
  bool is_space(const char);
  bool is_notvalid(const char);
  bool is_invalidchar(const char);


  // INPUT parsing methods
  void input_check(void);
  bool check_token(const std::string&);
  void find_tokens(void);


  
#ifdef DEBUG
  void print_checked_input(void);
  void print_found_tokens(void);
  void print_token_role(const std::string&);  
#endif

};
