
#include <gtest/gtest.h>
#include "extension.h"

TEST(add, _2and3is5)
{
    ASSERT_EQ(5, add(2, 3));
}

TEST(add, _3and3is6)
{
    ASSERT_EQ(6, add(3, 3));
}

TEST(add, _1and4is5)
{
    ASSERT_EQ(5, add(1, 4));
}

TEST(add, _2and4is6)
{
    ASSERT_EQ(6, add(2, 4));
}

// ----------------------- //

TEST(max_of_three, first)
{
    ASSERT_EQ(5, maxOfThree(5, 4, 3));
}

TEST(max_of_three, second)
{
    ASSERT_EQ(5, maxOfThree(4, 5, 3));
}

TEST(max_of_three, third)
{
    ASSERT_EQ(5, maxOfThree(3, 4, 5));
}

// ----------------------- //

TEST(median, four)
{
    ASSERT_EQ(5, median({7, 5, 3, 5}));
}

TEST(median, fourDiff)
{
    ASSERT_EQ(6, median({7, 5, 3, 8}));
}

TEST(median, five)
{
    ASSERT_EQ(3, median({1, 2, 3, 4, 5}));
}

TEST(median, fourDouble)
{
    ASSERT_EQ(3.5, median({2, 3, 4, 5}));
}

// ----------------------- //

TEST(is_vowel, a)
{
    ASSERT_TRUE(isVowel('a'));
}

TEST(is_vowel, u)
{
    ASSERT_TRUE(isVowel('u'));
}

TEST(is_vowel, A)
{
    ASSERT_FALSE(isVowel('b'));
}

// ----------------------- //

TEST(translate, bemutatkozik)
{
    ASSERT_EQ("bevemuvutavatkovozivik", translate("bemutatkozik"));
}

TEST(translate, lagopus)
{
    ASSERT_EQ("lavagovopuvus", translate("lagopus"));
}