#ifndef SamiCorrelationsApi_H_
#define SamiCorrelationsApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiCorrelation.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiCorrelationsApi {
public:
  SamiCorrelationsApi();
  virtual ~SamiCorrelationsApi();

  
  IList* 
  correlationsGetWithCompletion(String* effect, String* cause, void (* handler)(IList*, SamiError*));
  
  IList* 
  publicCorrelationsSearchSearchGetWithCompletion(String* search, String* effectOrCause, void (* handler)(IList*, SamiError*));
  
  static String getBasePath() {
    return L"https://localhost/api";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiCorrelationsApi_H_ */