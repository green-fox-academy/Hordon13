#include <iostream>
#include <string>

bool anagram(std::string, std::string, int);

int main(int argc, char *args[]) {

    std::string first;
    std::string second;

    std::cout << "Your first word?" << std::endl;
    std::cin >> first;

    std::cout << "Your second word?" << std::endl;
    std::cin >> second;

    int size = first.length();

    std::cout << anagram(first, second, size) << std::endl;

    return 0;
}

bool anagram(std::string input1, std::string input2, int len) {

    std::string test;

    for (int i = 0; i < len; ++i) {
        char letter = input1.at(i);

        for (int j = 0; j < len; ++j) {
            char match = input2.at(j);
            if (letter == match){
                test += letter;
                break;
            }
        }
    }

    return(input1 == test);
}