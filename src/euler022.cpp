#include "euler.hpp"

uint64 word_score(std::string word)
{
    uint64 score = 0;
    for (int i = 0; i < word.length(); i++) {
        char c = word.at(i);
        score += (int)(c - 'A' + 1);
    }
    return score;
}

void euler()
{
    auto names = readFile("data/euler022.txt", ',');
    for (std::string& name : names) {
        name = replace_all(name, "\"", "");
    }
    std::sort(names.begin(), names.end());

    uint64 result = 0;
    for (uint64 i = 0; i < names.size(); i++) {
        std::string current = names.at(i);
        uint64 score = word_score(current);
        uint64 name_score = (i+1) * score;
        result += name_score;
    }
    print(word_score("COLIN"));
    print(result);
}
