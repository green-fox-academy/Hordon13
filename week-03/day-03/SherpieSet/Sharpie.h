#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>

class Sharpie {
public:
    Sharpie(const std::string &color, float width);

    void use();

    const std::string &getColor() const;

    float getInkAmount() const;

    void setInkAmount(float inkAmount);

private:
    std::string color;
    float width;
    float inkAmount;
};


#endif
