#include "Animal.h"

Animal::Animal() : hunger(50), thirst(50)
{}

int Animal::getHunger() const
{
    return hunger;
}

void Animal::setHunger(int hunger)
{
    Animal::hunger = hunger;
}

int Animal::getThirst() const
{
    return thirst;
}

void Animal::setThirst(int thirst)
{
    Animal::thirst = thirst;
}

void Animal::eat()
{
    setHunger(--hunger);
}

void Animal::drink()
{
    setThirst(--thirst);
}

void Animal::play()
{
    setHunger(++hunger);
    setThirst(++thirst);
}