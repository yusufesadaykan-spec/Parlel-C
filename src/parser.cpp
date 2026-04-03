#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace parser
{
    std::vector<std::string> parse(const std::string& input) {
        std::vector<std::string> lines;
        std::stringstream ss(input);
        std::string line;

        // lets add some salt to our output
        while (std::getline(ss, line)) {
            lines.push_back(line);
        }

        return lines;
    }
};
