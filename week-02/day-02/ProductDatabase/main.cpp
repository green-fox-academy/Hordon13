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

    auto it = products.begin();

    for (; it != products.end(); ++it) {
        if (it->first == "Fish") {
            std::cout << "The fish cost: " << it->second << std::endl;
        }
    }

    it = products.begin();
    int max = 0;
    std::string maxProduct;
    for (; it != products.end(); ++it) {
        if (it->second > max) {
            max = it->second;
            maxProduct = it->first;
        }
    }
    std::cout << "The most expensive product is: " << maxProduct << std::endl;

    it = products.begin();
    int sum = 0;
    for (; it != products.end(); ++it) {
        sum += it->second;
    }
    std::cout << "The average price is: " << double(sum) / products.size() << std::endl;

    it = products.begin();
    int bellow;
    for (; it != products.end(); ++it) {
        if (it->second < 300) {
            ++bellow;
        }
    }
    std::cout << "There is  " << bellow << " product bellow 300." << std::endl;

    it = products.begin();
    int found = 0;
    std::string exact;
    for (; it != products.end(); ++it) {
        if (it->second == 125) {
            exact = it->first;
            ++found;
        }
    }
    if (found == 1) {
        std::cout << "There is a product, which is exactly 125:  " << exact << std::endl;
    } else {
        std::cout << "There is not any product, which is exactly 125." << std::endl;
    }

    it = products.begin();
    int min = max;
    std::string minProduct;
    for (; it != products.end(); ++it) {
        if (it->second < min) {
            min = it->second;
            minProduct = it->first;
        }
    }
    std::cout << "The cheapest product is: " << minProduct << std::endl;

    return 0;
}