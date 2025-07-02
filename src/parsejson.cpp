#include "myjson.hpp"
#include "parsing.hpp"
#include "utility.hpp"

#include <unordered_map>

JSON parseObject(const std::string &s, int begin, int end,
                 std::unordered_map<int, int> &bracepair) {
  int i = begin;
  JSON ans(JSONType::OBJECT);

  while (i < end) {
    while (s[i] != '"') {
      ++i;
    }
    ++i;
    std::string key = "";

    while (s[i] != '"') {
      key += s[i];
      ++i;
    }

    while (s[i] != ':') {
      ++i;
    }
    ++i;

    while (isSpace(s[i])) {
      ++i;
    }
    std::string value = "";

    if (s[i] == '{') {
      ans[key] = parseObject(s, i, bracepair[i], bracepair);
      i = bracepair[i] + 1;
      continue;
    } else if (s[i] == '[') {
      ans[key] = parseArray(s, i, bracepair[i], bracepair);
      i = bracepair[i] + 1;
      continue;
    }

    while (i < end && s[i] != ',') {
      value += s[i];
      ++i;
    }
    ans[key] = getValue(value);
  }
  return ans;
}

JSON parseArray(const std::string &s, int begin, int end,
                std::unordered_map<int, int> &bracepair) {
  int i = begin;
  JSON ans(JSONType::ARRAY);
  ++i;

  while (i < end) {
    while (isSpace(s[i])) {
      ++i;
    }
    std::string value = "";

    while (i < end && s[i] != ',') {
      value += s[i];
      ++i;
    }
    ++i;
    ans.appendArray(getValue(value));
  }
  return ans;
}

JSON parse(const std::string &s) {
  std::unordered_map<int, int> bracepair;
  findBracepair(s, bracepair);
  int i = 0;

  while (isSpace(s[i])) {
    ++i;
  }
  if (s[i] == '[') {
    return parseArray(s, i, bracepair[i], bracepair);
  }

  return parseObject(s, i, bracepair[i], bracepair);
}
