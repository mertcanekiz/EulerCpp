#include "euler.hpp"

void euler()
{
    uint64 result = 1;
    uint64 limit = 20;
    for (uint64 i = 2; i <= limit; i++) {
        result = lcm(i, result);
    }
    print(result);
}
