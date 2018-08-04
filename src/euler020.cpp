#include "euler.hpp"

void euler()
{
    std::cout << "anan" << std::endl;
    InfInt a = 1;
    for (unsigned int i = 2; i <= 100; i++) {
        a *= i;
    }
    std::string s(a.toString());
    unsigned int result = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        result += s.at(i) - '0';
    }
    print(result);
}
