//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H

#include "USBDevice.h"
#include "NetworkDevice.h"

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
    WirelessAdapter(std::string, int, int);

    void info();
};

#endif //WIRELESSADAPTER_WIRELESSADAPTER_H
