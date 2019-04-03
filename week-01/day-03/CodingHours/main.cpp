
#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long

    int dailyCodeAverage = 6;
    int semesterDuration = 17;

    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.

    int workdays = semesterDuration * 5;
    std::cout << workdays * dailyCodeAverage << std::endl;


    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int workingHoursAverage = 52;
    int weeklyCoding;
    weeklyCoding = 5 * dailyCodeAverage;
    std::cout << (float(weeklyCoding)/workingHoursAverage) * 100 << std::endl;

    return 0;
}

