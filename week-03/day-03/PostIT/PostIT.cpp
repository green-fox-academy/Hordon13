#include <iostream>
#include "PostIT.h"

PostIT::PostIT(std::vector<int> backGroundColor, std::string text, std::vector<int> textColor)
{
    setBackGroundColor(backGroundColor);
    setText(text);
    setTextColor(textColor);
}

void PostIT::setBackGroundColor(std::vector<int> backGroundColor)
{
    _backGroundColor = backGroundColor;
}

void PostIT::setText(std::string text)
{
    _text = text;
}

void PostIT::setTextColor(std::vector<int> textColor)
{
    _textColor = textColor;
}

std::vector<int> PostIT::getBackGroundColor()
{
    return _backGroundColor;
}

std::string PostIT::getText()
{
    return _text;
}

std::vector<int> PostIT::getTextColor()
{
    return _textColor;
}