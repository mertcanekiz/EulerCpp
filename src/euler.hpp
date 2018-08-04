#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <numeric>
#include <map>
#include <cmath>
#include "InfInt.h"
#include <set>

#define print(x) std::cout << x << std::endl;

using Clock = std::chrono::high_resolution_clock;

typedef unsigned long long uint64;

void euler();

int main()
{
    std::cout << "anan" << std::endl;
    auto t1 = Clock::now();
    euler();
    auto t2 = Clock::now();
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms" << std::endl;
}

class Sieve
{
    public:
        Sieve(uint64 limit=1000000)
        {
            sieve.resize(limit);
            uint64 crosslimit = (uint64) std::sqrt(limit);
            for (uint64 n = 4; n < limit; n += 2) {
                sieve[n] = true;
            }
            for (uint64 n = 3; n < crosslimit; n += 2) {
                if (!sieve[n]) {
                    for (uint64 m = n * n; m < limit; m += 2 * n) {
                        sieve[m] = true;
                    }
                }
            }
            for (uint64 n = 2; n < limit; n++) {
                if (!sieve[n]) primes.push_back(n);
            }
        }

        bool is_prime(uint64 n)
        {
            return !sieve[n];
        }

        uint64 prime(uint64 n) {
            return primes[n];
        }

        uint64 sum_primes() {
            uint64 sum = 0;
            for (uint64 p : primes)
                sum += p;
            return sum;
        }

        std::vector<bool> sieve;
        std::vector<uint64> primes;
};

uint64 fib(uint64 n)
{
    uint64 a = 0, b = 1;
    for (uint64 i = 0; i < n; i++) {
        uint64 tmp = a;
        a = b;
        b += tmp;
    }
    return a;
}

uint64 largest_prime_factor(uint64 n)
{
    uint64 x = n;
    uint64 largest = 0;
    uint64 counter = 2;
    while (counter * counter <= x) {
        if (x % counter == 0) {
            x /= counter;
            largest = counter;
        } else {
            counter++;
        }
    }

    if (x > largest) {
        largest = x;
    }

    return largest;
}


bool is_palindrome(std::string s)
{
    std::string rev = s;
    reverse(rev.begin(), rev.end());
    return rev == s;
}

bool is_palindrome(uint64 n)
{
    std::string s = std::to_string(n);
    return is_palindrome(s);
}

uint64 gcd(uint64 a, uint64 b)
{
    uint64 r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

uint64 lcm(uint64 a, uint64 b)
{
    return a / gcd(a, b) * b;
}

uint64 triangle(uint64 n)
{
    return n * (n + 1) / 2;
}

uint64 num_divisors(uint64 n, const std::vector<uint64>& primes)
{
    uint64 divisors = 1;
    uint64 exponent;
    uint64 number = n;
    for (uint64 i = 0; i < primes.size(); i++) {
        if (primes[i] * primes[i] > n) {
            return divisors * 2;
        }
        exponent = 1;
        while (number % primes[i] == 0) {
            exponent++;
            number /= primes[i];
        }
        divisors *= exponent;
        if (number == 1) return divisors;
    }
    return divisors;
}

uint64 collatz_length(uint64 n, uint64 acc=0)
{
    while (true) {
        if (n < 2) {
            return 1 + acc;
        }
        if (n % 2 == 0) {
            n /= 2;
            acc += 1;
            continue;
        } else {
            n = 3 * n + 1;
            acc += 1;
            continue;
        }
    }
}


uint64 choose(uint64 n, uint64 r)
{
    uint64 result = 1;
    for (uint64 i = 1; i <= r; i++) {
        result *= (n - r + i);
        result /= i;
    }
    return result;
}

std::vector<std::string> readFile(const char* filename, char delim = '\n')
{
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> result;
    while (std::getline(file, line, delim)) {
        result.push_back(std::string(line));
    }
    return result;
}

std::vector<uint64> divisors(uint64 n)
{
    std::vector<uint64> result;
    uint64 limit = (uint64) std::sqrt(n) + 1;
    for (uint64 i = 1; i < limit; i++) {
        if (n % i == 0 && i * i != n) {
            result.push_back(i);
            result.push_back(n/i);
        }
        if (n % i == 0 && i * i == n) {
            result.push_back(i);
        }
    }
    return result;
}

uint64 sum_divisors(uint64 n)
{
    uint64 limit = (uint64) std::sqrt(n) + 1;
    uint64 result = 0;
    for (uint64 i = 1; i < limit; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                result += i;
            } else {
                result += i;
                result += n / i;
            }
        }
    }
    return result;
}

std::string replace_all(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
