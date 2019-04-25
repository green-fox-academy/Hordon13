#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "sum.h"

TEST(appleTest, testApppleReturnIsApple)
{
    // Arrange

    // Act
    std::string returnValue = getApple();

    // Assert
    ASSERT_EQ(returnValue, "apple");
}

TEST(sumTest, testSumReturnVectorEmpty)
{
    // Arrange
    std::vector<int> testVector = {};

    // Act
    int returnSum = sum(testVector);

    // Assert
    ASSERT_EQ(returnSum, 0);
}

TEST(sumTest, testSumReturnVector1Element)
{
    // Arrange
    std::vector<int> testVector = {4};

    // Act
    int returnSum = sum(testVector);

    // Assert
    ASSERT_EQ(returnSum, 4);
}

TEST(sumTest, testSumReturnVectorMultipleElement)
{
    // Arrange
    std::vector<int> testVector = {4, 6, 10};

    // Act
    int returnSum = sum(testVector);

    // Assert
    ASSERT_EQ(returnSum, 20);
}

TEST(sumTest, testSumReturnVectorSumNegative)
{
    // Arrange
    std::vector<int> testVector = {4, 6, -15};

    // Act
    int returnSum = sum(testVector);

    // Assert
    ASSERT_EQ(returnSum, -5);
}