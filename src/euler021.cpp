#include "euler.hpp"

void euler()
{
    uint64 limit = 10000;
    std::vector<uint64> divisor_sums;
    std::set<uint64> results;
    for (uint i = 0; i < limit; i++) {
        divisor_sums.push_back(sum_divisors(i) - i);
    }
    for (uint i = 0; i < divisor_sums.size(); i++) {
        uint64 d = divisor_sums[i];
        if (d > divisor_sums.size()) {
            continue;
        }
        if (divisor_sums[d] == i && i != d) {
            results.insert(i);
        }
    }
    uint64 total = 0;
    for (auto r : results) {
        total += r;
    }
    print(total);
}
