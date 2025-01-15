#ifndef CUSTOM_COMPONENT_H
#define CUSTOM_COMPONENT_H

#include <vector>
#include <string>

// Utility function to split a string into a vector
std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
  size_t start = 0;
  size_t end = s.find(delimiter);
  std::vector<std::string> tokens;
  while (end != std::string::npos) {
    tokens.push_back(s.substr(start, end - start));
    start = end + delimiter.length();
    end = s.find(delimiter, start);
  }
  tokens.push_back(s.substr(start));
  return tokens;
}

#endif
