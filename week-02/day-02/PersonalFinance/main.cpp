#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<int> expenses = {500, 1000, 1250, 175, 800, 120};

    int sum;
    for (unsigned int i = 0; i < expenses.size(); ++i) {
        sum += expenses.at(i);
    }

    std::cout << "The total spending was: " << sum << std::endl;

    auto max = std::max_element(expenses.begin(), expenses.end());
    std::cout << "The maximum spending was: " << *max << std::endl;

    auto min = std::min_element(expenses.begin(), expenses.end());
    std::cout << "The minimum spending was: " << *min << std::endl;

    std::cout << "The average spending was: " << sum / expenses.size() << std::endl;

    return 0;
}