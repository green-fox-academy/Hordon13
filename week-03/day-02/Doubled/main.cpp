#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void decrypt(std::string);

int main()
{
    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    decrypt("../duplicated-chars.txt");

    return 0;
}

void decrypt(std::string path)
{

    std::ifstream file;
    file.exceptions(std::ifstream::failbit);

    try {
        file.open(path);

        std::string lines;
        while (getline(file, lines)) {

            std::istringstream subLine(lines);

            std::string words;
            while (getline(subLine, words, ' ')) {

                for (int i = 0; i < words.length(); ++i) {
                    std::cout << words.at(i);
                    ++i;
                }

                std::cout << ' ';
            }

            std::cout << std::endl;
        }
        
        file.close();

    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

}