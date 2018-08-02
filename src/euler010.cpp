#include "euler.hpp"

void euler()
{
    uint limit = 2000000;
    Sieve sieve(limit);
    print(sieve.sum_primes());
}
