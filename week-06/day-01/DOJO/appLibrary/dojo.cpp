#include "dojo.h"

#include <iostream>
#include <string>
#include <map>
#include <cctype>

int getIndex(int num, std::vector<int> vector)
{
    auto it = std::find(vector.begin(), vector.end(), num);

    if (it != vector.end()) {
        return std::distance(vector.begin(), it);
    } else {
        return -1;
    }
}

bool anagram(std::string str1, std::string str2)
{
    while (std::find(str1.begin(), str1.end(), ' ') != str1.end()) {
        str1.erase(std::find(str1.begin(), str1.end(), ' '));
    }

    while (std::find(str1.begin(), str1.end(), ' ') != str1.end()) {
        str2.erase(std::find(str2.begin(), str2.end(), ' '));
    }

    for (char &i : str1) {
        i = tolower(i);
    }

    for (char &i : str2) {
        i = tolower(i);
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}

std::string money(int money)
{
    std::map<int, std::string> converter = {{0,  "zero"},
                                            {1,  "one"},
                                            {2,  "two"},
                                            {3,  "three"},
                                            {4,  "four"},
                                            {5,  "five"},
                                            {6,  "six"},
                                            {7,  "seven"},
                                            {8,  "eight"},
                                            {9,  "nine"},
                                            {10, "ten"},
                                            {11, "eleven"},
                                            {12, "twelve"},
                                            {13, "thirteen"},
                                            {15, "fifteen"},
                                            {18, "eighteen"},
                                            {20, "twenty"},
                                            {30, "thirty"},
                                            {50, "fifty"},
                                            {80, "eighty"}};

    auto it = converter.find(money);

    std::string first, sec, third, lastTwoString;

    if (it != converter.end()) {
        return converter[money];
    } else {

        if (money / 100 > 0) {
            first = converter[money / 100] + " hundred and ";
        }

        int lastTwo = money % 100;
        auto it3 = converter.find(lastTwo);
        if (it3 != converter.end()) {
            lastTwoString = converter[lastTwo];
        } else {

            if (lastTwo % 10 != 0) {
                third = " " + converter[lastTwo % 10];
            }

            int firstDigit = lastTwo - (lastTwo % 10);
            auto it2 = converter.find(firstDigit);

            if (it2 != converter.end()) {
                sec = converter[firstDigit];
            } else {
                sec = converter[firstDigit / 10] + "ty";
            }

            lastTwoString = sec + third;
        }
    }

    return first + lastTwoString;
}