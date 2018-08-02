#include "euler.hpp"

void euler()
{
    uint64 i = 0;
    Sieve sieve(1000000);
    while (true) {
        uint64 current = triangle(i++);
        uint64 divisors = num_divisors(current, sieve.primes);
        if (divisors > 500) {
            print(current);
            break;
        }
    }
}
