#include <iostream>
#include <string>
#include <map>

int main() {

    std::map<std::string, double> products = {{"Milk",            1.07},
                                              {"Rice",            1.59},
                                              {"Eggs",            3.14},
                                              {"Cheese",          12.60},
                                              {"Chicken Breasts", 9.40},
                                              {"Apples",          2.31},
                                              {"Tomato",          2.58},
                                              {"Potato",          1.75},
                                              {"Onion",           1.10}};

    std::map<std::string, int> bobList = {{"Milk",            3},
                                          {"Rice",            2},
                                          {"Eggs",            2},
                                          {"Cheese",          1},
                                          {"Chicken Breasts", 4},
                                          {"Apples",          1},
                                          {"Tomato",          2},
                                          {"Potato",          1},};

    std::map<std::string, int> aliceList = {{"Rice",            1},
                                            {"Eggs",            5},
                                            {"Chicken Breasts", 2},
                                            {"Apples",          1},
                                            {"Tomato",          10}};

    std::map<std::string, double>::iterator prodIT = products.begin();
    std::map<std::string, int>::iterator aliceIT = aliceList.begin();
    std::map<std::string, int>::iterator bobIT = bobList.begin();

    int sumBob = 0;
    for (; bobIT != bobList.end(); ++bobIT) {
        sumBob += ;
    }
    std::cout << "Bob pay: " << sumBob << std::endl;

    int sumAlice = 0;
    for (; aliceIT != aliceList.end(); ++aliceIT) {
        sumAlice += ;
    }
    std::cout << "Alice pay: " << sumAlice << std::endl;

    return 0;
}