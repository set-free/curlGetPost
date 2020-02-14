#pragma once
#include <string>

class httpGet {
private:
  std::string url;
  std::string getResult;

public:
  std::string GetUrl(const std::string &URL);
};
