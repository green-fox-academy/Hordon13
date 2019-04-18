#include "Sharpie.h"

Sharpie::Sharpie(const std::string &color, float width) : color(color), width(width), inkAmount(100){}

void Sharpie::use()
{
    setInkAmount(--inkAmount);
}

const std::string &Sharpie::getColor() const
{
    return color;
}

float Sharpie::getInkAmount() const
{
    return inkAmount;
}

void Sharpie::setInkAmount(float inkAmount)
{
    Sharpie::inkAmount = inkAmount;
}