//
// Created by Horváth Donát on 2019-04-24.
//

#include <iostream>
#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(std::string id, int usbType, int bandwidth) : USBDevice(id, usbType),
                                                                               NetworkDevice(id, bandwidth), Device(id)
{}

void WirelessAdapter::info()
{
    std::string usb;
    if (_usbType == 0) {
        usb = "USB Type 2";
    } else if (_usbType == 1) {
        usb = "USB Type 3";
    }
    std::cout << "The " << getID() << " " << usb << " wireless adapter has a " << _bandwidth << "Gbps bandwidth."
              << std::endl;
}