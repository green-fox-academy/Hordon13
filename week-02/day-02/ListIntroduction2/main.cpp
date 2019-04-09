#include <iostream>
#include <vector>
#include <string>

void printVector(std::vector<std::string>);

int main() {

    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

    std::vector<std::string> listB = listA;

    printVector(listA);
    printVector(listB);

    std::vector<std::string>::iterator it = std::find(listA.begin(), listA.end(), "Durian");

    if (it != listA.end()) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "NOT Found" << std::endl;
    }

    listB.erase(listB.begin() + 3);

    bool compare = std::equal(listA.begin(), listA.end(), listB.begin(), listB.end());

    if (compare == 1) {
        std::cout << "They are the same" << std::endl;
    } else {
        std::cout << "They are different" << std::endl;
    }

    for (unsigned int i = 0; i < listA.size(); ++i) {
        if (listA.at(i) == "Avocado") {
            std::cout << "The Avocado is at: " << i << std::endl;
        }
    }

    int found = 0;
    for (unsigned int i = 0; i < listB.size(); ++i) {
        if (listB.at(i) == "Durian") {
            std::cout << "The Durian is at: " << i << std::endl;
            ++found;
        }
    }
    if (found == 0) {
        std::cout << "Durian was not found!" << std::endl;
    }


    listB.insert(listB.end(), {"Passion Fruit", "Pummelo"});

    std::cout << listA.at(2) << std::endl;

    return 0;
}

void printVector(std::vector<std::string> vec) {
    for (unsigned int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}