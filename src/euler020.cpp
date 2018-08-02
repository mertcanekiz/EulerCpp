#include "euler.hpp"

void euler()
{
    mpz_t a;
    mpz_init(a);
    mpz_set_str(a, "1", 10);
    for (unsigned int i = 2; i <= 100; i++) {
        mpz_mul_ui(a, a, i);
    }
    std::string s(mpz_get_str(nullptr, 10, a));
    uint64 result = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        result += s.at(i) - '0';
    }
    print(result);
}
