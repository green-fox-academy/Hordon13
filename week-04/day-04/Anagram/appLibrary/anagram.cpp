#include "anagram.h"

bool anagram(std::string string1, std::string string2)
{
    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());

    if (string1 == string2) {
        return true;
    } else {
        return false;
    }
}
