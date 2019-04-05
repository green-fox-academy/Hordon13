#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one

    int first;
    int second;

    std::cout << "First number?" << std::endl;
    std::cin >> first;

    std::cout << "Second number?" << std::endl;
    std::cin >> second;

    if(first > second){
        std::cout << "The bigger one is the first one: " << first << std::endl;
    } else {
        std::cout << "The bigger one is:the second one: " << second << std::endl;
    }

    return 0;
}