#include "euler.hpp"

void euler()
{
    uint64 limit = 28123;
    std::vector<uint64> abundant_numbers;
    std::vector<bool> abundant_sums(limit+1);
    for (uint64 i = 1; i < limit; i++) {
        if (sum_divisors(i) - i > i) {
            abundant_numbers.push_back(i);
        }
    }
    for (uint64 i = 0; i < abundant_numbers.size(); i++) {
        for (uint64 j = i; j < abundant_numbers.size(); j++) {
            uint64 a1 = abundant_numbers[i];
            uint64 a2 = abundant_numbers[j];
            uint64 current = a1 + a2;
            if (current <= limit) {
                abundant_sums[current] = true;
            } else {
                break;
            }
        }
    }

    uint64 total = 0;
    for (uint64 i = 0; i < abundant_sums.size(); i++) {
        if (!abundant_sums[i]) {
            total += i;
        }
    }
    print(total);
}
