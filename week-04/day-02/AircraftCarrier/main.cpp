#include <iostream>
#include "Aircrafts.h"
#include "F16.h"
#include "F35.h"

int main()
{
    F16 f16;
    F35 f35;

    std::cout << f16.getStatus() << std::endl;
    f16.refill(5);
    std::cout << f16.refill(5) << std::endl;
    std::cout << f16.getStatus() << std::endl;
    std::cout << f16.getType() << std::endl;
    std::cout << f16.isPriority() << std::endl;
    std::cout << f16.fight() << std::endl;

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    std::cout << f35.getStatus() << std::endl;
    f35.refill(8);
    std::cout << f35.refill(15) << std::endl;
    std::cout << f35.getStatus() << std::endl;
    std::cout << f35.getType() << std::endl;
    std::cout << f35.isPriority() << std::endl;
    std::cout << f35.fight() << std::endl;

    return 0;
}