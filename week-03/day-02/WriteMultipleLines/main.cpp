#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void writeFile(std::string, std::string &, int);

int main()
{
    std::string path = "../text.txt";
    std::string word = "apple";
    int lines = 5;

    writeFile(path, word, lines);

    return 0;
}

void writeFile(std::string path, std::string &word, int lines)
{
    std::ofstream file;
    file.open(path);

    for (int i = 0; i < lines; ++i) {
        file << word << std::endl;
    }

    file.close();

}