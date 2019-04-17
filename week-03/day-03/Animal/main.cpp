#include <iostream>
#include "Animal.h"
#include <string>

int main()
{
    Animal anim;

    anim.play();
    anim.eat();
    anim.eat();
    anim.drink();

    std::cout << std::to_string(anim.getThirst()) << std::endl;
    std::cout << std::to_string(anim.getHunger()) << std::endl;

    return 0;
}