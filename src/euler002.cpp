#include "euler.hpp"

void euler()
{
    uint64 current = 0, total = 0;
    uint64 limit = 4000000;
    uint64 i = 0;
    while (current < limit) {
        current = fib(i++);
        if (current % 2 == 0) total += current;
    }
    print(total);
}
