#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{

    struct Computer lenovo;
    Notebook dell;

    lenovo.cpu_speed_GHz = 1.7;
    lenovo.ram_size_GB = 8;
    lenovo.bits = 32;

    dell.cpu_speed_GHz = 2.4;
    dell.ram_size_GB = 16;
    dell.bits = 64;

    printf("The first computer has a %.2f GHz processor, %d GB RAM and it has a %d bit system.\n",
           lenovo.cpu_speed_GHz, lenovo.ram_size_GB, lenovo.bits);

    printf("The second computer has a %.2f GHz processor, %d GB RAM and it has a %d bit system.",
           dell.cpu_speed_GHz, dell.ram_size_GB, dell.bits);

    return 0;
}