#pragma once

#include <string>

//The type of symbols
enum class SymbolType {
    ERROR = -1,
    EMPTY = 0,
    DECNUMBER,
    HEXNUMBER,
    OCTNUMBER,
    BINNUMBER,
    IDENTIFIER,
    STRING
};

//Token
struct Token {
    SymbolType type;
    std::string token;
};