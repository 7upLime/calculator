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
  std::string INPUT;
  std::string CHECKED_INPUT;
  std::string m_buffer{""};
  std::string m_filename;
  
 public:

  Scanner(std::string& filename) : m_filename{filename} {}

  // Token check
  bool is_function(const std::string&); // they all make use of m_buffer
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
  void pre_check(void);
  // void print_token(const std::string&);  


  
#ifdef DEBUG
  void print_checked_input(void);
#endif

};
