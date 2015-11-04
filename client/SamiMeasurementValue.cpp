
#include "SamiMeasurementValue.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiMeasurementValue::SamiMeasurementValue() {
    init();
}

SamiMeasurementValue::~SamiMeasurementValue() {
    this->cleanup();
}

void
SamiMeasurementValue::init() {
    pStart_time = null;
    pValue = null;
    
}

void
SamiMeasurementValue::cleanup() {
    if(pStart_time != null) {
        
        delete pStart_time;
        pStart_time = null;
    }
    if(pValue != null) {
        
        delete pValue;
        pValue = null;
    }
    
}


SamiMeasurementValue*
SamiMeasurementValue::fromJson(String* json) {
    this->cleanup();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
    return this;
}


void
SamiMeasurementValue::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pStart_timeKey = new JsonString(L"start_time");
        IJsonValue* pStart_timeVal = null;
        pJsonObject->GetValue(pStart_timeKey, pStart_timeVal);
        if(pStart_timeVal != null) {
            
            pStart_time = new Long();
            jsonToValue(pStart_time, pStart_timeVal, L"Long", L"Long");
        }
        delete pStart_timeKey;
        JsonString* pValueKey = new JsonString(L"value");
        IJsonValue* pValueVal = null;
        pJsonObject->GetValue(pValueKey, pValueVal);
        if(pValueVal != null) {
            
            pValue = new Float();
            jsonToValue(pValue, pValueVal, L"Float", L"Float");
        }
        delete pValueKey;
        
    }
}

SamiMeasurementValue::SamiMeasurementValue(String* json) {
    init();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
}

String
SamiMeasurementValue::asJson ()
{
    JsonObject* pJsonObject = asJsonObject();

    char *pComposeBuf = new char[256];
    JsonWriter::Compose(pJsonObject, pComposeBuf, 256);
    String s = String(pComposeBuf);

    delete pComposeBuf;
    pJsonObject->RemoveAll(true);
    delete pJsonObject;

    return s;
}

JsonObject*
SamiMeasurementValue::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    
    JsonString *pStart_timeKey = new JsonString(L"start_time");
    pJsonObject->Add(pStart_timeKey, toJson(getPStartTime(), "Long", ""));

    
    JsonString *pValueKey = new JsonString(L"value");
    pJsonObject->Add(pValueKey, toJson(getPValue(), "Float", ""));

    
    return pJsonObject;
}

Long*
SamiMeasurementValue::getPStartTime() {
    return pStart_time;
}
void
SamiMeasurementValue::setPStartTime(Long* pStart_time) {
    this->pStart_time = pStart_time;
}

Float*
SamiMeasurementValue::getPValue() {
    return pValue;
}
void
SamiMeasurementValue::setPValue(Float* pValue) {
    this->pValue = pValue;
}



} /* namespace Swagger */
