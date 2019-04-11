#include <iostream>

std::string change(std::string);

int main() {

    std::string input;
    std::cout << "Give me a string: ";
    std::cin >> input;

    std::cout << change(input);

    return 0;
}

std::string change(std::string in) {

    if (in.size() < 1) {
        return "*";
    }

    int len = in.length() - 1;
    char temp = in.at(len);
    in.pop_back();
    return change(in) + temp + '*';
}