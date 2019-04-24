//
// Created by Horváth Donát on 2019-04-24.
//

#include "USBDevice.h"

USBDevice::USBDevice(std::string id, int usbType) : Device(id)
{
    _usbType = usbType;
}