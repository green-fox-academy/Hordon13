#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {

    std::map<int, std::string> mapTask;

    if (mapTask.empty() == 1) {
        std::cout << "The map is empty!" << std::endl;
    } else {
        std::cout << "The map is NOT empty" << std::endl;
    }

    mapTask.insert(std::make_pair(97, "a"));
    mapTask.insert(std::make_pair(98, "b"));
    mapTask.insert(std::make_pair(99, "c"));
    mapTask.insert(std::make_pair(65, "A"));
    mapTask.insert(std::make_pair(66, "B"));
    mapTask.insert(std::make_pair(67, "C"));

    //auto myIterator = mapTask.begin();
    std::map<int, std::string>::iterator myIterator = mapTask.begin();

    for (; myIterator != mapTask.end(); ++myIterator) {
        std::cout << myIterator->first << std::endl;
    }

    auto it2 = mapTask.begin();
    for (; it2 != mapTask.end(); ++it2) {
        std::cout << it2->second << std::endl;
    }

    mapTask.insert(std::make_pair(68, "D"));

    std::cout << mapTask.at(99) << std::endl;

    mapTask.erase(97);


    if (mapTask.count(100) == 0) {

        std::cout << "Does NOT exist" << std::endl;
    } else {
        std::cout << "Exist" << std::endl;
    }

    mapTask.clear();

    return 0;
}