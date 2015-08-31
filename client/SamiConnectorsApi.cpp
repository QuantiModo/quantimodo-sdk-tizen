#include "SamiConnectorsApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiConnectorsApi::SamiConnectorsApi() {

}

SamiConnectorsApi::~SamiConnectorsApi() {

}

void
v1ConnectorsListGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    IList* out = new ArrayList();
    jsonToValue(out, pJson, L"IList*", L"SamiConnector");

    if (pJson) {
      if (pJson->GetType() == JSON_TYPE_OBJECT) {
         JsonObject* pObject = static_cast< JsonObject* >(pJson);
         pObject->RemoveAll(true);
      }
      else if (pJson->GetType() == JSON_TYPE_ARRAY) {
         JsonArray* pArray = static_cast< JsonArray* >(pJson);
         pArray->RemoveAll(true);
      }
      handler(out, null);
    }
    else {
      SamiError* error = new SamiError(0, new String(L"No parsable response received"));
      handler(null, error);
    }
    
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    handler(null, error);
    
  }
}

IList* 
SamiConnectorsApi::v1ConnectorsListGetWithCompletion( void (* success)(IList*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1ConnectorsListGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  

  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  

  String* mBody = null;

  

  String url(L"/v1/connectors/list");

  

  client->execute(SamiConnectorsApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}

void
v1ConnectorsConnectorConnectGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    handler(null, null);
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    
    handler(error, null);
  }
}

void 
SamiConnectorsApi::v1ConnectorsConnectorConnectGetWithCompletion(String* connector, void(*success)(SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1ConnectorsConnectorConnectGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  

  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  

  String* mBody = null;

  

  String url(L"/v1/connectors/{connector}/connect");

  
  String s_connector(L"{");
  s_connector.Append(L"connector");
  s_connector.Append(L"}");
  url.Replace(s_connector, stringify(connector, L"String*"));
  

  client->execute(SamiConnectorsApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  
}

void
v1ConnectorsConnectorDisconnectGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    handler(null, null);
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    
    handler(error, null);
  }
}

void 
SamiConnectorsApi::v1ConnectorsConnectorDisconnectGetWithCompletion(String* connector, void(*success)(SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1ConnectorsConnectorDisconnectGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  

  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  

  String* mBody = null;

  

  String url(L"/v1/connectors/{connector}/disconnect");

  
  String s_connector(L"{");
  s_connector.Append(L"connector");
  s_connector.Append(L"}");
  url.Replace(s_connector, stringify(connector, L"String*"));
  

  client->execute(SamiConnectorsApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  
}

void
v1ConnectorsConnectorInfoGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiConnectorInfo* out = new SamiConnectorInfo();
    jsonToValue(out, pJson, L"SamiConnectorInfo*", L"SamiConnectorInfo");

    if (pJson) {
      if (pJson->GetType() == JSON_TYPE_OBJECT) {
         JsonObject* pObject = static_cast< JsonObject* >(pJson);
         pObject->RemoveAll(true);
      }
      else if (pJson->GetType() == JSON_TYPE_ARRAY) {
         JsonArray* pArray = static_cast< JsonArray* >(pJson);
         pArray->RemoveAll(true);
      }
      handler(out, null);
    }
    else {
      SamiError* error = new SamiError(0, new String(L"No parsable response received"));
      handler(null, error);
    }
    
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    handler(null, error);
    
  }
}

SamiConnectorInfo* 
SamiConnectorsApi::v1ConnectorsConnectorInfoGetWithCompletion(String* connector, void (* success)(SamiConnectorInfo*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1ConnectorsConnectorInfoGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  

  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  

  String* mBody = null;

  

  String url(L"/v1/connectors/{connector}/info");

  
  String s_connector(L"{");
  s_connector.Append(L"connector");
  s_connector.Append(L"}");
  url.Replace(s_connector, stringify(connector, L"String*"));
  

  client->execute(SamiConnectorsApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}

void
v1ConnectorsConnectorUpdateGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    handler(null, null);
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    
    handler(error, null);
  }
}

void 
SamiConnectorsApi::v1ConnectorsConnectorUpdateGetWithCompletion(String* connector, void(*success)(SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1ConnectorsConnectorUpdateGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  

  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  

  String* mBody = null;

  

  String url(L"/v1/connectors/{connector}/update");

  
  String s_connector(L"{");
  s_connector.Append(L"connector");
  s_connector.Append(L"}");
  url.Replace(s_connector, stringify(connector, L"String*"));
  

  client->execute(SamiConnectorsApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  
}


} /* namespace Swagger */
