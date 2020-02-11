#include <curl/curl.h>

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
//#include <sstream>

using namespace curlpp::options;
int main(int argc, char *argv[]) {
  std::cout << argc << " :: " << argv << std::endl;
  std::string myUrl = "https://ya.ru";
  try {
    curlpp::Cleanup MyCleanup;
    curlpp::Easy myRequest;
    myRequest.setOpt<Url>(myUrl);
    myRequest.setOpt(new Verbose(true));
    myRequest.perform();
  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

