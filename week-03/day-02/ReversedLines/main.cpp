#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void decrypt(std::string);

int main()
{
    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    decrypt("../reversed-lines.txt");

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
            std::reverse(lines.begin(), lines.end());
            std::cout << lines << std::endl;
        }

        file.close();

    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

}