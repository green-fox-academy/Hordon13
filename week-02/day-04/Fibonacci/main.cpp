#include <iostream>

int fibonacci(int);

int main() {

    int nthPoint;
    std::cout << "Fibonacci(n) | n = ";
    std::cin >> nthPoint;

    std::cout << fibonacci(nthPoint) << std::endl;

    return 0;
}

int fibonacci(int n) {

    //todo: Ha 1 írok be, nullát kéne visszaadnia
    if (n - 2 <= 1) {
        return 1;
    }

    return (fibonacci(n - 2) + fibonacci(n - 1));
}