#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy(std::string &, std::string &);

int main()
{
    std::string fileToCopy = "../text.txt";
    std::string copied = "../text_copy.txt";

    std::cout << copy(fileToCopy, copied) << std::endl;

    return 0;
}

bool copy(std::string &from, std::string &to)
{

    std::ifstream file(from);
    std::ofstream fileCopy(to);

    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        fileCopy << line << std::endl;
    }

    return true;
}