#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[]{3, 4, 5, 6, 7};
    int rev_aj[5];
    for (int i = 0; i < 5; ++i) {
        rev_aj[i] = {aj[4 - i]};
        std::cout << rev_aj[i] << std::endl;
    }

    return 0;
}