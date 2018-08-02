#include "euler.hpp"

void euler()
{
    uint64 result = 0;
    for (uint64 i = 999; i > 900; i--) {
        for (uint64 j = i; j > 900; j--) {
            uint64 current = i * j;
            if (is_palindrome(current) && current > result) {
                result = current;
            }
        }
    }
    print(result);
}
