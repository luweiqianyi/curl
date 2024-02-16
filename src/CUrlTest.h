#ifndef CURL_TEST_H
#define CURL_TEST_H

#include <gtest/gtest.h>
#include "CUrlFunctionTest.h"

TEST(CUrlFunctionTest, SimpleHttpGetRequest)
{
    CUrlFunctionTest tInstance;
    tInstance.SimpleHttpGetRequest();
}

TEST(CUrlFunctionTest, SimpleHttpGetRequestAndSaveResponseToMemeory)
{
    CUrlFunctionTest tInstance;
    tInstance.SimpleHttpGetRequestAndSaveResponseToMemeory();
}

#endif