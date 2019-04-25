#include <iostream>
#include <gtest/gtest.h>

#include "fibonacci.h"

TEST(FibonacciTest, testFibNum0)
{

    int index = 0;

    int result = fibonacci(index);

    ASSERT_EQ(result, 0);
}

TEST(FibonacciTest, testFibNum1)
{

    int index = 1;

    int result = fibonacci(index);

    ASSERT_EQ(result, 1);
}

TEST(FibonacciTest, testFibNum3)
{

    int index = 2;

    int result = fibonacci(index);

    ASSERT_EQ(result, 1);
}

TEST(FibonacciTest, testFibNum10)
{

    int index = 10;

    int result = fibonacci(index);

    ASSERT_EQ(result, 55);
}