#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void decrypt(std::string);

int main()
{
    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.

    decrypt("../reversed-order.txt");

    return 0;
}

void decrypt(std::string path)
{

    std::ifstream file;
    file.exceptions(std::ifstream::failbit);

    std::vector<std::string> reversed;

    try {

        file.open(path);
        std::string lines;
        while (getline(file, lines)) {
            reversed.insert(reversed.begin(), lines);
        }

        for (unsigned int i = 0; i < reversed.size(); ++i) {
            std::cout << reversed[i] << "\n";
        }

        file.close();

    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

}