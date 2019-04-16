#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> uniqueIP(std::string);

double ratio(std::string);

int main()
{
    std::vector<std::string> ipAdressesUnique;
    ipAdressesUnique = uniqueIP("../log.txt");

    for (unsigned int i = 0; i < ipAdressesUnique.size(); ++i) {
        std::cout << ipAdressesUnique[i] << std::endl;
    }

    std::cout << ratio("../log.txt") << std::endl;

    return 0;
}

std::vector<std::string> uniqueIP(std::string path)
{
    std::ifstream file(path);
    std::vector<std::string> ipCollection;

    std::string lines;
    while (getline(file, lines)) {
        std::istringstream subString(lines);
        std::string adressesIP;
        int it = 0;

        while (getline(subString, adressesIP, ' ')) {
            ++it;
            if (it == 9) {
                ipCollection.push_back(adressesIP);
            }
        }
    }

    std::sort(ipCollection.begin(), ipCollection.end());
    ipCollection.erase(std::unique(ipCollection.begin(), ipCollection.end()), ipCollection.end());

    return ipCollection;
}

double ratio(std::string path)
{
    double sumGet = 0;
    double sumPost = 0;
    std::ifstream file(path);

    std::string lines;
    while (getline(file, lines)) {
        std::istringstream subString(lines);
        int it = 0;

        std::string eachLine;
        while (getline(subString, eachLine, ' ')) {
            ++it;
            if (it == 12) {
                if (eachLine == "POST") {
                    ++sumPost;
                } else {
                    ++sumGet;
                }
            }
        }
    }

    return sumGet / sumPost;
}
