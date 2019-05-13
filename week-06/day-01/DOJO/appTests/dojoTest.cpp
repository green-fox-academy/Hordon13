#include <iostream>
#include <gtest/gtest.h>

#include "dojo.h"

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