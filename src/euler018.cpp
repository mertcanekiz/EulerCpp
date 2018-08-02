#include "euler.hpp"

void euler()
{
    auto data = readFile("data/euler018.txt");
    uint64 triangle[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            triangle[i][j] = 0;
        }
    }
    for (int i = 0; i < data.size(); i++) {
        std::string line = data.at(i);
        std::istringstream f(line);
        std::string s;
        int j = 0;
        while (std::getline(f, s, ' ')) {
            triangle[i][j] = std::stoi(s);
            j++;
        }
    }

    for (int i = 14; i > 0; i--) {
        for (int j = 0; j < 14; j++) {
            triangle[i-1][j] += std::max(triangle[i][j], triangle[i][j+1]);
        }
    }

    print(triangle[0][0]);
}
