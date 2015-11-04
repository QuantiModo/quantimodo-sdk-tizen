/*
 * SamiInline_response_200_3.h
 * 
 * 
 */

#ifndef SamiInline_response_200_3_H_
#define SamiInline_response_200_3_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiConnection.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Boolean;


namespace Swagger {

class SamiInline_response_200_3: public SamiObject {
public:
    SamiInline_response_200_3();
    SamiInline_response_200_3(String* json);
    virtual ~SamiInline_response_200_3();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiInline_response_200_3* fromJson(String* obj);

    
    IList* getPData();
    void setPData(IList* pData);
    
    Boolean* getPSuccess();
    void setPSuccess(Boolean* pSuccess);
    

private:
    IList* pData;
    Boolean* pSuccess;
    
};

} /* namespace Swagger */

#endif /* SamiInline_response_200_3_H_ */
