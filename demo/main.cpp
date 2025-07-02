#include "myjson.hpp"
#include "parsing.hpp"
#include "serializing.hpp"

#include <iostream>

int main() {
  const std::string jsonstring =
      "{\"array\":[1,2,3],\"boolean\":true,\"color\":\"gold\",\"null\":null,"
      "\"number\":123,\"object\":{\"a\":\"b\",\"c\":\"d\"},\"string\":"
      "\"HelloWorld\"}";
  JSON json1(parse(jsonstring));

  std::cout << "array third element is " << int(json1["array"][2]) << std::endl;
  std::cout << "value of color is " << std::string(json1["color"]) << std::endl;
  std::cout << "value of a in object is " << std::string(json1["object"]["a"])
            << std::endl;
  std::cout << "value of number is " << int(json1["number"]) << std::endl;
  std::cout << std::endl;

  JSON json = JSON(JSONType::OBJECT);
  json["name"] = "IAmNidhogg";
  json["age"] = 24;
  json["height"] = 174.5;
  json["tag"] = std::vector<JSON>{"connect", "fight"};
  json["enemies"] = nullptr;
  json["valid"] = true;
  json["unit"] = JSON(JSONType::OBJECT);
  json["unit"]["name"] = "BRIDGES";

  std::string s = stringify(json);
  std::cout << "stringify result:\n" << s << std::endl;

  // Test parsing from stringified JSON.
  auto ans = parse(s);
  std::cout << "finished parsing" << std::endl;

  // parsing the strigified json.
  std::cout << "Result of parsing the stringified json:\n"
            << stringify(ans) << std::endl;

  return 0;
}
