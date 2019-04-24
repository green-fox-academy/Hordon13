//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H

#include <string>
#include "Device.h"

class USBDevice : public virtual Device {
public:
    USBDevice(std::string, int);

protected:
    int _usbType;
};

#endif //WIRELESSADAPTER_USBDEVICE_H
