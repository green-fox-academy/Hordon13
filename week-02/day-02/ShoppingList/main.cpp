#include <iostream>
#include <string>
#include <vector>

int main() {

    std::vector<std::string> shoppingList = {"Eggs", "milk", "fish", "apples", "bread", "chicken"};

    int found = 0;
    auto search = shoppingList.begin();
    for (; search != shoppingList.end(); ++search) {
        if (*search == "milk") {
            std::cout << "Yes, we have milk." << std::endl;
            found++;
        }
    }
    if (found == 0) { std::cout << "There is no milk on the list." << std::endl; }

    found = 0;
    search = shoppingList.begin();
    for (; search != shoppingList.end(); ++search) {
        if (*search == "bananas") {
            std::cout << "Yes, we have bannanas." << std::endl;
            found++;
        }
    }
    if (found == 0) { std::cout << "There is no bananas on the list." << std::endl; }

    return 0;
}