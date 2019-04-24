#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer3D.h"
#include "Printer2D.h"
#include "Scanner.h"
#include "Copier.h"

int main(int argc, char *args[])
{
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.


    std::vector<Printer *> devices;

    Printer2D printer2DFirst(20, 30);
    devices.push_back(&printer2DFirst);
    Printer2D printer2DSecond(25, 35);
    devices.push_back(&printer2DSecond);
    Printer2D printer2DThird(30, 40);
    devices.push_back(&printer2DThird);

    Printer3D printer3DFirst(5, 10, 15);
    devices.push_back(&printer3DFirst);
    Printer3D printer3DSecond(6, 11, 16);
    devices.push_back(&printer3DSecond);

    Copier copier(12, 12, 120);
    devices.push_back(&copier);

    for (int i = 0; i < devices.size(); ++i) {
        devices[i]->print();
    }

    std::vector<Scanner *> scanners;

    Scanner scanner1(130);
    scanners.push_back(&scanner1);
    Scanner scanner2(150);
    scanners.push_back(&scanner2);

    Copier copier2(13, 13, 130);
    scanners.push_back(&copier2);
    Copier copier3(14, 14, 140);
    scanners.push_back(&copier3);

    for (int j = 0; j < scanners.size(); ++j) {
        scanners[j]->scan();
    }

    Copier copier4(15, 15, 150);
    copier4.copy();

}