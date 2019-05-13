#include <iostream>
#include <gtest/gtest.h>

#include "dojo.h"

// Tests for get index

TEST(getIndex, numIsInTheList)
{
    std::vector<int> vector = {2, 6, 102, 33, 0, 78, -12, 43};
    int num = 102;

    int index = getIndex(num, vector);

    ASSERT_EQ(index, 2);
}

TEST(getIndex, numIsNotInTheList)
{
    std::vector<int> vector = {2, 6, 102, 33, 0, 78, -12, 43};
    int num = 8;

    int index = getIndex(num, vector);

    ASSERT_EQ(index, -1);
}

TEST(getIndex, numIsATTheListEnd)
{
    std::vector<int> vector = {2, 6, 102, 33, 0, 78, -12, 43};
    int num = 43;

    int index = getIndex(num, vector);

    ASSERT_EQ(index, 7);
}

// Test for anagram

TEST(anagram, isAnagramTRUE)
{
    // Arrange
    std::string str1 = "listen";
    std::string str2 = "silent";

    // Act
    bool isAnagram = anagram(str1, str2);

    // Assert
    ASSERT_TRUE(isAnagram);
}

TEST(anagram, isAnagramFALSE)
{
    // Arrange
    std::string str1 = "listen";
    std::string str2 = "here";

    // Act
    bool isAnagram = anagram(str1, str2);

    // Assert
    ASSERT_FALSE(isAnagram);
}

TEST(anagram, UppercaseTrue)
{
    // Arrange
    std::string str1 = "listen";
    std::string str2 = "SILENT";

    // Act
    bool isAnagram = anagram(str1, str2);

    // Assert
    ASSERT_TRUE(isAnagram);
}

TEST(anagram, withSpace)
{
    // Arrange
    std::string str1 = "list en";
    std::string str2 = "SILENT";

    // Act
    bool isAnagram = anagram(str1, str2);

    // Assert
    ASSERT_TRUE(isAnagram);
}

TEST(anagram, withMultipleSpace)
{
    // Arrange
    std::string str1 = "li st en";
    std::string str2 = "SILENT";

    // Act
    bool isAnagram = anagram(str1, str2);

    // Assert
    ASSERT_TRUE(isAnagram);
}

// Test for money converter

TEST(moneyConverter, oneDigit)
{
    // Arrange
    int number = 3;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "three");
}

TEST(moneyConverter, twoDigit)
{
    // Arrange
    int number = 86;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "eighty six");
}

TEST(moneyConverter, endZero)
{
    // Arrange
    int number = 60;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "sixty");
}

TEST(moneyConverter, specialNum)
{
    // Arrange
    int number = 11;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "eleven");
}

TEST(moneyConverter, threeDigit)
{
    // Arrange
    int number = 576;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "five hundred and seventy six");
}

TEST(moneyConverter, threeSpecialDigit)
{
    // Arrange
    int number = 411;

    // Act
    std::string converted = money(number);

    // Assert
    ASSERT_EQ(converted, "four hundred and eleven");
}