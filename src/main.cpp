#include <iostream>

#include "httplib.hpp"

int main(int argc, char *argv[]) {
  std::cout << "argc: " << argc << "\nargv: " << argv
            << "\nargv[1]: " << argv[1] << std::endl;
  std::string getUrl = argv[1];
  httpGet HTTP;
  auto httpContent = HTTP.GetUrl(getUrl);
  std::cout << "Content:\n" << httpContent << std::endl;
  return 0;
}
