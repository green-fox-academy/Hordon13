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

void Sharpie::setColor(const std::string &color)
{
    Sharpie::color = color;
}

float Sharpie::getWidth() const
{
    return width;
}

void Sharpie::setWidth(float width)
{
    Sharpie::width = width;
}

float Sharpie::getInkAmount() const
{
    return inkAmount;
}

void Sharpie::setInkAmount(float inkAmount)
{
    Sharpie::inkAmount = inkAmount;
}
