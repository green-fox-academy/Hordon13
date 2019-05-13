#include "dojo.h"
#include <iostream>
#include <string>
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