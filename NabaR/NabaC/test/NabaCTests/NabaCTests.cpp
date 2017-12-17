// NabaCTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define GTEST_HAS_TR1_TUPLE 0

#include "gtest/gtest.h"

#include "src/gtest-all.cc"

GTEST_API_ int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

