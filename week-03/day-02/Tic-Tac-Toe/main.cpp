#include <iostream>
#include <fstream>
#include <string>

std::string ticTacResult(std::string);

int main()
{
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("../win-o.txt");
    // should print O

    std::cout << ticTacResult("../win-x.txt");
    // should print X

    std::cout << ticTacResult("../draw.txt");
    // should print draw

    return 0;
}

// Alapelv: csak az a meccs lehet döntetlen, amikor egyik sorban sincs egymás mellett azonos karakter
//          ellenkező esetben az a nyertes, akinek több karaktere van a táblán.

std::string ticTacResult(std::string path)
{

    std::ifstream file;
    file.exceptions(std::ifstream::failbit);

    try {

        file.open(path);

        int x = 0;
        int o = 0;
        bool draw = true;

        std::string line;
        while (getline(file, line)) {

            for (int i = 0; i < 3; ++i) {
                if (line.at(i) == 'O') {
                    ++o;
                } else {
                    ++x;
                }
            }

            for (int j = 0; j < 2; ++j) {
                if (line.at(j) == line.at(j + 1)) {
                    draw = false;
                }
            }

        }

        if (draw) {
            return "draw";
        } else if (x > o) {
            return "X";
        } else {
            return "O";
        }

    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
}