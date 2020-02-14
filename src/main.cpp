#include <iostream>

#include "httplib.hpp"

int main(int argc, char *argv[]) {
  std::cout << argc << " :: " << argv << std::endl;
  std::string getUrl = argv[1];
  httpGet HTTP;
  HTTP.GetUrl(getUrl);
  return 0;
}

