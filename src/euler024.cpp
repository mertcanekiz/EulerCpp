#include "euler.hpp"

void euler()
{
    std::string s("0123456789");
    uint64 limit = 1000000;
    for(uint64 i = 1; i < limit; i++)
    {
        std::next_permutation(s.begin(), s.end());
    }
    print(s);
}
