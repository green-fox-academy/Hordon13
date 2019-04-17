#include <iostream>
#include "PostIT.h"
#include <string>

int main()
{
    PostIT one({255, 128, 0, 255}, "Idea 1", {0, 0, 255, 255});
    PostIT two({255, 0, 255, 255}, "Awesome", {0, 0, 0, 255});
    PostIT three({255, 255, 0, 255}, "Superb!", {0, 255, 0, 255});

    std::cout << one.getText() << std::endl;

    return 0;
}