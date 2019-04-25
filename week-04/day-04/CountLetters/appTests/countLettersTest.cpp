#include <iostream>
#include <gtest/gtest.h>

#include "countLetters.h"

TEST(countLetterTest, testIfEqualsTrue)
{
    // Arrange
    std::string testString = "aaabbcc";
    std::map<char, int> expectedMap = {{'a', 3},
                                       {'b', 2},
                                       {'c', 2}};

    // Act
    std::map<char, int> result = letterCount(testString);

    // Assert
    ASSERT_EQ(result, expectedMap);
}

TEST(countLetterTest, testIfNotEqualsFalse)
{
    // Arrange
    std::string testString = "aaabbccd";
    std::map<char, int> expectedMap = {{'a', 3},
                                       {'b', 2},
                                       {'c', 2}};

    // Act
    std::map<char, int> result = letterCount(testString);

    // Assert
    ASSERT_NE(result, expectedMap);
}