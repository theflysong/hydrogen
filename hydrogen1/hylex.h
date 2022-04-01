#pragma once

#include "hysym.h"

#include <vector>

//Initialize the lexer
void initLexer(void);

// Lex the Input
std::vector<Token> lex(std::string input);