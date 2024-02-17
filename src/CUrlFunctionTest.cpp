#include "CUrlFunctionTest.h"
#include <curl/curl.h>

const char *common_request_url = "http://118.89.66.17:8081/";

CUrlFunctionTest::CUrlFunctionTest()
{
}

CUrlFunctionTest::~CUrlFunctionTest()
{
}

void CUrlFunctionTest::TestAllFunctions()
{
    SimpleHttpGetRequest();
    SimpleHttpGetRequestAndSaveResponseToMemeory();
}

/// @brief 接收Http响应回调函数
/// @param contents
/// @param size
/// @param nmemb
/// @param arg
/// @return
size_t CUrlFunctionTest::ReceiveHttpResponseCallback(void *contents, size_t size, size_t nmemb, void *arg)
{
    size_t realsize = size * nmemb;
    CUrlFunctionTest *tInstance = (CUrlFunctionTest *)arg;
    if (tInstance == nullptr)
    {
        return realsize;
    }
    tInstance->AppendHttpResponseFrom(contents, realsize);

    return realsize;
}

void CUrlFunctionTest::AppendHttpResponseFrom(void *src, int len)
{
    mHttpResponse.append((char*)src, len);
}

void CUrlFunctionTest::ClearHttpResponse()
{
    mHttpResponse.clear();
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
        curl_easy_setopt(curl, CURLOPT_URL, common_request_url);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}

/// @brief Http get请求测试，并保存响应到内存，然后输出到控制台
void CUrlFunctionTest::SimpleHttpGetRequestAndSaveResponseToMemeory()
{
    ClearHttpResponse(); // 清空上一次的请求响应

    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    if (curl_handle != nullptr)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, common_request_url);

        // 设置响应接收回调函数和响应接收对象
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, CUrlFunctionTest::ReceiveHttpResponseCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, this);

        // 设置User-Agent域
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        // 发送请求
        res = curl_easy_perform(curl_handle);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else
        {
            printf("received http response:\n%s\nreceived http response(end)\n", mHttpResponse.c_str());
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();
}

void CUrlFunctionTest::SimpleHttpPostRequestAndSaveResponseToMemeory()
{
    ClearHttpResponse(); // 清空上一次的请求响应

    CURL *curl = curl_easy_init();
    if (curl) {
        // 设置post请求的请求路径
        const char* post_url = "http://localhost:8002/register";
        curl_easy_setopt(curl, CURLOPT_URL, post_url);

        // 设置响应接收回调函数和响应接收对象
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CUrlFunctionTest::ReceiveHttpResponseCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

        // 初始化 curl_mime 对象
        curl_mime *mime = curl_mime_init(curl);

        // 添加表单字段
        curl_mimepart *field1 = curl_mime_addpart(mime);
        curl_mime_name(field1, "accountName");
        curl_mime_data(field1, "BaiJuyi", CURL_ZERO_TERMINATED);

        curl_mimepart *field2 = curl_mime_addpart(mime);
        curl_mime_name(field2, "password");
        curl_mime_data(field2, "123456", CURL_ZERO_TERMINATED);

        // 设置 POST 请求类型
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // 将 curl_mime 对象添加到请求中
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

        // 执行请求
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) 
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("received http response:\n%s\nreceived http response(end)\n", mHttpResponse.c_str());
        }

        // 释放资源
        curl_mime_free(mime);
        curl_easy_cleanup(curl);
    }
}