#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

    int p1[3] = {1, 2, 3};
    int p2[2] = {4, 5};

    int p1Elements = sizeof(p1) / sizeof(int);
    int p2Elements = sizeof(p2) / sizeof(int);

    if (p1Elements < p2Elements) {
        std::cout << "Yes, p2 has more elements." << std::endl;
    } else {
        std::cout << "No, p1 is bigger." << std::endl;
    }


    return 0;
}