#include <iostream>
#include <fstream>
#include "parser.cpp"
#include <vector>
#include <string>
#include <sstream>
#include "error.cpp"

std::vector<std::string> fileToVector(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        err.throwShit("Moduler" , Critical , "some shit is hiding from us");
        return lines;
    }

    std::string currentLine;
    while (std::getline(file, currentLine)) {
        
        lines.push_back(currentLine);
    }

    file.close();
    return lines;
}

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "arch isnt there\n";
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}

bool writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cout << "arch is stuck";
        return false;
    }
    
    file << content;
    return true;
}

struct moduler
{
    std::vector<std::string> archs;
    void getModules(std::string outputF)
    {
        std::string outputFormat = " ";
        for (std::string arch : archs)
        {
            outputFormat += readFile(arch);
            outputFormat += "\n";
        }
        writeFile(outputF, outputFormat);
    }
    void loadParse(std::vector<std::string> parse, std::string outputF)
    {
        std::string outputFormat = " ";
        for (std::string p : parse)
        {
            outputFormat += p;
            outputFormat += "\n";
        }

        std::string f = readFile(outputF);
        writeFile(outputF, f+=outputFormat);
    }
};
