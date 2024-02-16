#include <cstdio>
#include <curl/curl.h>
#include <gtest/gtest.h>

// https://everything.curl.dev/examples

void SimpleHttpRequest()
{
    printf("Hello world\n");
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com/");

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}

TEST(CURL, SimpleHttpRequest)
{
    SimpleHttpRequest();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}