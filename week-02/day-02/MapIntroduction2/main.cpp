#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string, std::string> map = {{"978-1-60309-452-8", "A Letter to Jo"},
                                              {"978-1-60309-459-7", "Lupus"},
                                              {"978-1-60309-461-0", "The Lab"},
                                              {"978-1-60309-444-3", "Red Panda and Moon Bear"}};

    std::map<std::string, std::string>::iterator it = map.begin();

    for (; it != map.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first << ")" << std::endl;
    }

    map.erase("978-1-60309-444-3");

    std::cout << std::endl;

    it = map.begin();
    for (; it != map.end(); ++it) {
        if (it->second == "The Lab") {
            map.erase(it);
        }
    }

    it = map.begin();
    for (; it != map.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first << ")" << std::endl;
    }

    map.insert({{"978-1-60309-450-4", "They Called Us Enemy"},
                {"978-1-60309-453-5", "Why Did We Trust Him?"}});


    auto search = map.find("478-0-61159-424-8");

    if (search != map.end()) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    search = map.find("978-1-60309-453-5");
    if (search != map.end()) {
        std::cout << search->second << std::endl;
    } else {
        std::cout << "Value Not found" << std::endl;
    }

    return 0;
}