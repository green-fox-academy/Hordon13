//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H

#include <string>
#include "Device.h"

class NetworkDevice : public virtual Device {
public:
    NetworkDevice(std::string, int);

protected:
    int _bandwidth;
};

#endif //WIRELESSADAPTER_NETWORKDEVICE_H
