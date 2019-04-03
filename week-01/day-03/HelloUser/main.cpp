#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::cout << "Whats is your name?" << std::endl;
    std::string userName;

    std::cin >> userName;
    std::cout << "Hello " << userName << std::endl;

    return 0;
}