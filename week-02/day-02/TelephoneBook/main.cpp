#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string, std::string> telephoneBook = {{"William A. Lathan",   "405-709-1865"},
                                                        {"John K. Miller",      "402-247-8568"},
                                                        {"Hortensia E. Foster", "606-481-6467"},
                                                        {"Amanda D. Newland",   "319-243-5613"},
                                                        {"Brooke P. Askew",     "307-687-2982"}};

    std::map<std::string, std::string>::iterator search = telephoneBook.begin();
    int notFound = 0;

    for (; search != telephoneBook.end(); ++search) {
        if (search->first == "John K. Miller") {
            std::cout << "The number you looking for is: " << search->second << std::endl;
            notFound++;
        }
    }
    if (notFound == 0) { std::cout << "Not Found..." << std::endl; }

    search = telephoneBook.begin();
    notFound = 0;

    for (; search != telephoneBook.end(); ++search) {
        if (search->second == "307-687-2982") {
            std::cout << "The person you looking for is: " << search->first << std::endl;
            notFound++;
        }
    }
    if (notFound == 0) { std::cout << "Not Found..." << std::endl; }

    search = telephoneBook.begin();
    notFound = 0;

    for (; search != telephoneBook.end(); ++search) {
        if (search->first == "Chris E. Myers") {
            std::cout << "The number you looking for is: " << search->second << std::endl;
            notFound++;
        }
    }
    if (notFound == 0) { std::cout << "Not Found..." << std::endl; }

    return 0;
}