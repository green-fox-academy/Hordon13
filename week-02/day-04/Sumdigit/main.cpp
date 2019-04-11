#include <iostream>

int digitSum(int, int);

int main() {

    std::cout << digitSum(12345, 0) << std::endl;

    return 0;
}

int digitSum(int num, int sum) {

    if (num / 10 == 0) {
        return num + sum;
    }

    sum += num % 10;
    return digitSum(num / 10, sum);
}