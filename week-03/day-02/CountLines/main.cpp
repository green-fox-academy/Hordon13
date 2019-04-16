#include <iostream>
#include <fstream>
#include <string>

int lines(std::string);

int main()
{
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::cout << lines("text.txt") << std::endl;

    return 0;
}

int lines(std::string fileName)
{
    std::ifstream myFile(fileName);

    if (myFile.is_open()) {

        std::string lines;
        int numLines;

        while (getline(myFile, lines)) {
            ++numLines;
        }

        myFile.close();
        return numLines;


    } else {
        return 0;
    }

}