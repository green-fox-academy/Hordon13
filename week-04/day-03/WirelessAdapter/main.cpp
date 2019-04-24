#include <iostream>
#include "Device.h"
#include "USBDevice.h"
#include "NetworkDevice.h"
#include "WirelessAdapter.h"

enum USBType {
    USB_TYPE_2,
    USB_TYPE_3
};

int main(int argc, char *args[])
{
    WirelessAdapter adapter("da4c32fb21", USB_TYPE_2, 100);
    adapter.info();
}

