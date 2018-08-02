#include "euler.hpp"

void euler()
{
    Sieve sieve;
    uint64 num_primes = 1;
    uint64 n = 1;
    uint64 limit = 10001;
    while (num_primes < limit)
    {
        n += 2;
        if (sieve.is_prime(n))
            num_primes++;
    }
    print(n);
}
