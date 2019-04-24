//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef WIRELESSADAPTER_DEVICE_H
#define WIRELESSADAPTER_DEVICE_H

#include <string>

class Device {
public:
    Device(std::string);

    std::string getID();

private:
    std::string _id;
};


#endif //WIRELESSADAPTER_DEVICE_H
