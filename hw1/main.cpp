#include <iostream>
#include <cstdlib>

std::string get_build_number() {
    const char* build_number = std::getenv("BUILD_NUMBER");
    if (build_number != nullptr) {
        return build_number;
    } else {
        return "N/A";
    }
}

bool validate_version(const std::string& version) {
    for (char c : version) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

int main() {

    std::string build_number = get_build_number();
    std::cout << "build " << build_number << std::endl;
    std::cout << "Hello, World!" << std::endl;

    if (validate_version(build_number)) {
        std::cout << "Version number is valid" << std::endl;
    } else {
        std::cout << "Version number is invalid" << std::endl;
    }

    return 0;
}
