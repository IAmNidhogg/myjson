#include "myjson.hpp"

std::string stringify(const JSON &node) {
  switch (node._type) {
  case JSONType::BOOL:
    return node._value._bool ? "true" : "false";
  case JSONType::NULLT:
    return "null";
  case JSONType::NUMBER: {
    if (node._value._numbertype == 1) {
      return std::to_string(node._value._dnumber);
    } else if (node._value._numbertype == 2) {
      return std::to_string(node._value._inumber);
    }
  }

  case JSONType::STRING: {
    std::string ans = "\"";
    ans += node._value._string;
    ans += '"';
    return ans;
  }

  case JSONType::ARRAY: {
    std::string ans = "[";
    for (auto i : node._array) {
      ans += stringify(i);
      ans += ',';
    }
    ans[ans.length() - 1] = ']';
    return ans;
  }

  case JSONType::OBJECT: {
    std::string ans = "{";
    for (auto &j : node._data) {
      ans += '"';
      ans += j.first;
      ans += '"';
      ans += ':';
      ans += stringify(j.second);
      ans += ',';
    }
    ans[ans.length() - 1] = '}';
    return ans;
  }
  }
}
