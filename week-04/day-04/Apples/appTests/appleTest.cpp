#include <iostream>
#include <gtest/gtest.h>
#include "apple.h"

TEST(appleTest, testApppleReturnIsApple){

    // Arrange

    // Act
    std::string returnValue = getApple();

    // Assert
    ASSERT_EQ(returnValue, "apple");
}