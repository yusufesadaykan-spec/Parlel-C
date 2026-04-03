#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <sstream>
#define byte uint8_t

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "flamingo in flame : reading shitted\n";
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}

bool writeFile(const std::string& filePath, const auto& content) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cout << "flamingo in flame : writing shitted";
        return false;
    }
    
    file << content;
    return true;
}
