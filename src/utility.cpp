#include <string>
#include <unordered_map>
#include <vector>

#include "myjson.hpp"

void findBracepair(const std::string &s,
                   std::unordered_map<int, int> &bracepair) {
  std::vector<int> stack;
  int l = s.length();

  for (int i = 0; i < l; ++i) {
    if (s[i] == '[' || s[i] == '{') {
      stack.push_back(i);
    } else if (s[i] == ']' || s[i] == '}') {
      bracepair[stack.back()] = i;
      stack.pop_back();
    }
  }
}

bool isSpace(char c) { return c == ' ' || c == '\n'; }

bool isDouble(const std::string &s) {
  int i = 0;
  if (s[0] == '+' || s[0] == '-') {
    ++i;
  }

  bool dotdetect = false;

  while (i < s.length()) {
    if (!std::isdigit(s[i]) && s[i] != '.') {
      return false;
    }
    if (s[i] == '.') {
      if (dotdetect)
        return false;
      dotdetect = true;
    }
    ++i;
  }
  return dotdetect;
}

bool isInteger(const std::string &s) {
  int i = 0;
  if (s[0] == '+' || s[0] == '-') {
    i++;
  }

  while (i < s.length()) {
    if (!std::isdigit(s[i])) {
      return false;
    }
    i++;
  }
  return true;
}

JSON getValue(const std::string &s) {
  int i = 0;
  int j = s.length() - 1;
  while (isSpace(s[i])) {
    ++i;
  }
  while (isSpace(s[j])) {
    --j;
  }
  std::string tmp = s.substr(i, j - i + 1);

  if (tmp[0] == '"') {
    return JSONNode(tmp.substr(1, tmp.length() - 2));
  }
  if (tmp == "true" || tmp == "false") {
    return JSONNode(s == "true");
  }
  if (tmp == "null") {
    return JSONNode(nullptr);
  }
  if (isDouble(tmp)) {
    return JSONNode(std::stod(tmp));
  }
  if (isInteger(tmp)) {
    return JSONNode(std::stoi(tmp));
  }

  return JSONNode(tmp);
}
