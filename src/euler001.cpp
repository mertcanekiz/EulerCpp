#include "euler.hpp"

void euler()
{
    uint64 total = 0;
    for (uint64 i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            total += i;
        }
    }
    print(total);
}
