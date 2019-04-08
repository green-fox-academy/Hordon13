#include <iostream>

void palindrome(std::string, int);

int main() {

    std::string word;
    std::cout << "Give me an expression:" << std::endl;
    std::getline(std::cin, word);

    int len = word.length();

    palindrome(word, len);


    return 0;
}

void palindrome(std::string input, int len) {

    char middle;
    char before;
    char after;
    std::string palindrome;

    for (int i = 1; i < len - 1; ++i) {
        middle = input.at(i);
        before = input.at(i - 1);
        after = input.at(i + 1);

        if (before == after) {
            palindrome += before;
            palindrome += middle;
            palindrome += after;
        }
    }

    std::cout << palindrome << std::endl;
}