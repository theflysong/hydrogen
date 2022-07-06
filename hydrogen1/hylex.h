#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace hydrogen {
    //单词
    struct Token {
        enum TokenType {
            DecNumber,
            HexNumber,
            OctNumber,
            BinNumber,
            Identifier,
            String,
            Error
        };
        TokenType type; //单词类型
        std::string value; //单词内容
    };

    std::string ToString(Token::TokenType type);

    class Lexer {
        std::istream &input; //输入流
        Token DecNumber();
        Token OctNumber();
        Token HexNumber();
        Token BinNumber();
        Token Number();
    public:
        Lexer(std::istream &input);
        ~Lexer();
        Token LexOnce();
        std::vector<Token> Lex();
    };
}