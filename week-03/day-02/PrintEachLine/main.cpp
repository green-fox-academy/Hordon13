#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream fileRead;
    fileRead.open("my-file.txt");

    std::string line;

    while (getline(fileRead, line)) {
        std::cout << line << std::endl;
    }

    fileRead.close();

    return 0;
}