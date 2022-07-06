#include <hylex.h>
#include <iostream>


int main(int argc, const char **argv) {
    using namespace hydrogen;

    Lexer lexer(std::cin);

    Token token = lexer.LexOnce();

    std::cout << ToString(token.type) << ":" << token.value << std::endl;
    return 0;
}