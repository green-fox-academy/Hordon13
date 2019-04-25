#include "fibonacci.h"
#include <vector>

int fibonacci(int index)
{
    std::vector<int> fibNumbers;
    fibNumbers.push_back(0);
    fibNumbers.push_back(1);

    for (int i = 1; i < index; ++i) {
        fibNumbers.push_back(fibNumbers[i] + fibNumbers[i - 1]);
    }
    return fibNumbers[index];
}