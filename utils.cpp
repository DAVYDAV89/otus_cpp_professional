// -*- mode: c++; coding: utf-8 -*-
#include <sstream>
#if __has_include(<bit>)
#  include <bit>
#endif

#include "utils.h"


namespace core
{

std::string get_build_ticker()
{
  return __DATE__;
}

std::vector<std::string> split(const std::string & s, char delimiter)
{
  std::vector<std::string> items;
  split_into(s, delimiter, items);
  return items;
}

void split_into(const std::string& s, char delimiter, std::vector<std::string>& into)
{
  into.clear();
  std::string item;
  std::istringstream iss(s);
  while (std::getline(iss, item, delimiter))
  {
    into.push_back(item);
  }
}

std::string trim(const std::string& s, const char* _whitespaces)
{
  const std::string whitespaces(_whitespaces);
  const std::size_t from = s.find_first_not_of(whitespaces);
  if (from == std::string::npos) return "";
  std::string res = s.substr(from);
  const std::size_t to = res.find_last_not_of(whitespaces);
  if (to == std::string::npos) return "";
  return res.substr(0, to + 1);
}

}
