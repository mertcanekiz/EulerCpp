#include "euler.hpp"

std::string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
std::string elevens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twelve"};
std::string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

std::string num2word(uint64 n)
{
    if (n < 10) {
        return ones[n-1];
    }
    if (n == 10) {
        return tens[0];
    }
    if (n < 20) {
        return elevens[n-11];
    }
    if (n < 100) {
        uint64 a = n / 10;
        uint64 b = n % 10;
        if (b == 0) {
            return tens[a-1];
        }
        return std::string(tens[a-1] + num2word(b));
    }
    if (n < 1000) {
        uint64 a = n / 100;
        uint64 bc = n % 100;
        if (bc == 0) {
            return std::string(ones[a-1] + "hundred");
        }
        return std::string(ones[a-1] + "hundredand" + num2word(bc));
    }
    if (n == 1000) {
        return "onethousand";
    }
}


void euler()
{
    uint64 limit = 1000;
    uint64 result = 0;
    for (uint64 i = 1; i <= limit; i++) {
        std::string current = num2word(i);
        result += current.length();
    }
    print(result);
}
