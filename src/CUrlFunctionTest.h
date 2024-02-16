#ifndef CURL_FUNCTIONS_TEST_H
#define CURL_FUNCTIONS_TEST_H

class CUrlFunctionTest
{   
public:
    CUrlFunctionTest();
    ~CUrlFunctionTest();

    void Test();

protected:
    void SimpleHttpGetRequest();
};

#endif