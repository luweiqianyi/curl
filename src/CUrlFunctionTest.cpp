#include"CUrlFunctionTest.h"
#include <curl/curl.h>

CUrlFunctionTest::CUrlFunctionTest()
{
}

CUrlFunctionTest::~CUrlFunctionTest()
{
}

void CUrlFunctionTest::Test()
{
    SimpleHttpGetRequest();
}

// https://everything.curl.dev/examples

/// @brief 测试Http get请求
void CUrlFunctionTest::SimpleHttpGetRequest()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://118.89.66.17:8081/");

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}