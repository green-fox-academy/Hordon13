#include <iostream>
#include <string>
#include <map>

int main() {

    std::map<std::string, int> products = {{"Eggs",    200},
                                           {"Milk",    200},
                                           {"Fish",    400},
                                           {"Apples",  150},
                                           {"Bread",   50},
                                           {"Chicken", 550}};

    std::map<std::string, int>::iterator it = products.begin();
    std::cout << "These products cost less than 201: ";
    for (; it != products.end(); ++it) {
        if (it->second < 201) {
            std::cout << it->first << " ";
        }
    }
    std::cout << std::endl;

    it = products.begin();
    std::cout << "These products cost more than 150: ";
    for (; it != products.end(); ++it) {
        if (it->second > 150) {
            std::cout << it->first << "(" << it->second << ") ";
        }
    }
    std::cout << std::endl;

    return 0;
}