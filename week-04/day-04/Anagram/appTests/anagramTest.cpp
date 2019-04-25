#include <iostream>
#include <gtest/gtest.h>
#include "anagram.h"

TEST(AnagramTest, testAnagramTrue)
{
    // Arrange
    std::string str1 = "gyomorrontás";
    std::string str2 = "toronymorgás";

    // Act
    bool result = anagram(str1, str2);

    //Assert
    ASSERT_EQ(result, true);
}

TEST(AnagramTest, testNotAnagramFalse)
{
    // Arrange
    std::string str1 = "gyomorrontások";
    std::string str2 = "toronymorgás";

    // Act
    bool result = anagram(str1, str2);

    //Assert
    ASSERT_EQ(result, false);
}

TEST(AnagramTest, testAnagramMultipleCharFalse)
{
    // Arrange
    std::string str1 = "gyomorrontássss";
    std::string str2 = "toronymorgás";

    // Act
    bool result = anagram(str1, str2);

    //Assert
    ASSERT_EQ(result, false);
}