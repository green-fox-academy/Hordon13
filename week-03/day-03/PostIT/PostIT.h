#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H
#include <vector>

class PostIT {

private:
    std::vector<int> _backGroundColor;
    std::string _text;
    std::vector<int> _textColor;
public:
    PostIT(std::vector<int> backGroundColor, std::string text, std::vector<int> textColor);

    void setBackGroundColor(std::vector<int> backGroundColor);

    void setText(std::string text);

    void setTextColor(std::vector<int> textColor);

    std::vector<int> getBackGroundColor();

    std::string getText();

    std::vector<int> getTextColor();
};

#endif