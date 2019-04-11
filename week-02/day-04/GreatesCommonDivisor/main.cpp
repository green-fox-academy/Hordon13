#include <iostream>

int comDiv(int, int);

int main() {

    int num1, num2;
    std::cout << "Number 1?" << std::endl;
    std::cin >> num1;

    std::cout << "Number 2?" << std::endl;
    std::cin >> num2;

    if (num2 > num1) {
        std::swap(num2, num1);
    }

    std::cout << comDiv(num1, num2) << std::endl;

    return 0;
}

int comDiv(int num1, int num2) {

    if (num1 % num2 == 0) {
        return num2;
    }

    return comDiv(num2, num1 - num2);
}