#include "countLetters.h"

std::map<char, int> letterCount(std::string input)
{
    std::map<char, int> charMap;
    char actualChar;
    int sumActualChar;

    std::sort(input.begin(), input.end());

    for (int i = 0; i < input.length(); ++i) {
        actualChar = input[i];
        sumActualChar = 1;
        for (int j = i + 1; j < input.length() + 1; ++j) {
            if (input[i] == input[j] && j != input.length() + 1) {
                ++sumActualChar;
            } else {
                std::pair<char, int> insertToMap = std::make_pair(actualChar, sumActualChar);
                charMap.insert(insertToMap);
            }
        }
    }
    return charMap;
}