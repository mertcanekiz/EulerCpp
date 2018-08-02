#include "euler.hpp"

void euler()
{
    std::ifstream data("data/euler013.txt");
    std::string line;
    mpz_t sum, current;
    mpz_inits(sum, current, nullptr);
    mpz_set_str(sum, "0", 10);
    while (std::getline(data, line)) {
        std::istringstream iss(line);
        mpz_set_str(current, iss.str().c_str(), 10);
        mpz_add(sum, sum, current);
    }
    mpz_out_str(stdout, 10, sum);
    print("")
}
