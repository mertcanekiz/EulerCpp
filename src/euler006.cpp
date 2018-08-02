#include "euler.hpp"

void euler()
{
    uint64 limit = 100;
    uint64 squareOfSum = limit * limit * (limit + 1) * (limit + 1) / 4;
    uint64 sumOfSquare = 0;
    for (uint64 i = 1; i <= limit; i++)
    {
        sumOfSquare += i * i;
    }
    print(squareOfSum - sumOfSquare);
}
