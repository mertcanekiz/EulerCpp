#include "euler.hpp"

void euler()
{
    mpz_t base;
    mpz_inits(base, nullptr);
    mpz_set_str(base, "2", 10);
    mpz_pow_ui(base, base, 1000);
    std::string number(mpz_get_str(nullptr, 10, base));
    uint64 total = 0;
    for (uint64 i = 0; i < number.length(); i++) {
        total += number.at(i) - '0';
    }
    print(total);
}
