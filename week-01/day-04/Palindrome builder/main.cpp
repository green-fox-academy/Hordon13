#include <iostream>
#include <string>

std::string palindrome(std::string);

int main(int argc, char *args[]) {

    std::string word;

    std::cout << "Your word?" << std::endl;
    std::cin >> word;

    std::cout << palindrome(word) << std::endl;

    return 0;
}

std::string palindrome(std::string input) {

    std::string reversed;
    int len = input.length();
    for (int i = 0; i < len; ++i) {
        reversed += input.at(len-1 - i);
    }

    return(input + reversed);
}