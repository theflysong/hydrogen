#include <iostream>
#include "hylex.h"

int main(int argc, const char **argv) {
    initLexer();
    std::string str;
    std::getline(std::cin, str);
    auto tokens = lex(str);
    for (auto tok : tokens)
        std::cout << "(" << (int)tok.type << ":" << tok.token << ")";
    return 0;
}