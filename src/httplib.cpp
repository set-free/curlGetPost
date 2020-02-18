#include "httplib.hpp"

#include <curl/curl.h>

#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <sstream>

std::string httpGet::GetUrl(const std::string &URL) {
  url = URL;
  try {
    std::string url = URL;
    std::ostringstream response;
    curlpp::Cleanup MyCleanup;
    curlpp::Easy myRequest;
    myRequest.setOpt<curlpp::options::Url>(url);
    myRequest.setOpt(new curlpp::options::Verbose(false));
    myRequest.setOpt(new curlpp::options::WriteStream(&response));
    myRequest.perform();
    getResult = response.str();
    //    std::cout << "Begin response:\n" << response.str() << "\nEnd
    //    response... ";
    cURLpp::Options::Url myUrl;
    myRequest.getOpt(myUrl);
    //    std::cout << "\nRequested url: " << myUrl.getValue() << std::endl;
  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
  }
  return getResult;
}
