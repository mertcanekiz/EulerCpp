#include "euler.hpp"

void euler()
{
    uint limit = 1000;
    for (uint a = 1; a < limit / 2; a++)
    {
        for (uint b = a; b < limit / 2; b++)
        {
            uint c = limit - b - a;
            if (a * a + b * b == c * c)
            {
                print(a * b * c);
                return;
            }
        }
    }
}
