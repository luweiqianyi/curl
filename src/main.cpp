#include <cstdio>
#include <gtest/gtest.h>
#include "CUrlFunctionTest.h"

TEST(CUrlFunctionTest, Test)
{
    CUrlFunctionTest tInstance;
    tInstance.Test();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}