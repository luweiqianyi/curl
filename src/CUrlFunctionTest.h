#ifndef CURL_FUNCTIONS_TEST_H
#define CURL_FUNCTIONS_TEST_H

#include <string>

class CUrlFunctionTest
{   
public:
    CUrlFunctionTest();
    ~CUrlFunctionTest();

    void TestAllFunctions();
public:
    static size_t ReceiveHttpResponseCallback(void *contents, size_t size, size_t nmemb, void *arg);
    void AppendHttpResponseFrom(void* src,int len);
    
protected:
    void SimpleHttpGetRequest();
    void SimpleHttpGetRequestAndSaveResponseToMemeory();

    void ClearHttpResponse();

protected:
    std::string mHttpResponse;
};

#endif