#include "hylex.h"
#include <assert.h>
#include <cmath>

//the matrix of the automata
int transMatrix[14][13] = {
    { 1,  2,  2,  2,  3,  3,  3,  3,  7, -1, -1, -1, -1},
    { 4,  4,  4, -1, -1,  5, -1,  6, -1, -1, -1, -1, -1},
    { 2,  2,  2,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { 3,  3,  3,  3,  3,  3,  3,  3, -1, -1, -1, -1, -1},
    { 4,  4,  4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { 5,  5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { 6,  6,  6,  6,  6,  6, -1, -1, -1, -1, -1, -1, -1},
    { 7,  7,  7,  7,  7,  7,  7,  7,  8, -1,  9,  7, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {10, 10, 10, 10,  7,  7,  7, 12,  7,  7,  7,  7, -1},
    {11, 11, 11, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { 7,  7,  7,  7, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {13, 13, 13, 13, 13, 13, -1, -1, -1, -1, -1, -1, -1},
    { 7,  7,  7,  7,  7,  7, -1, -1, -1, -1, -1, -1, -1}
};

//mapping character to the input of automata
//characters with the same properties share same index
int char_mapping[128] = {};

void initLexer(void) {
    //arr[ [min, max] ] = val;
    #define range_set(min, max, val) for (int i = min ; i <= max ; i ++) char_mapping[i] = val

    //initialize the mapping
    range_set(0, 127, 11);
    char_mapping['0'] = 0;
    char_mapping['1'] = 1;
    range_set('2', '7', 2);
    range_set('8', '9', 3);
    //letter b will get a new index later
    range_set('a', 'f', 4);
    range_set('A', 'F', 4);
    char_mapping['b']=char_mapping['B'] = 5;
    //letter x will get a new index later
    range_set('g', 'z', 6);
    range_set('G', 'Z', 6);
    char_mapping['_'] = 6;
    char_mapping['x'] = char_mapping['X'] = 7;
    char_mapping['"'] = 8;
    char_mapping['\n'] = char_mapping['\r'] = 9;
    char_mapping['\\'] = 10;

    #undef range_set
}

//mapping the last state of automata to the type of symbol
SymbolType state2type[14] = {SymbolType::EMPTY, SymbolType::DECNUMBER, SymbolType::DECNUMBER, SymbolType::IDENTIFIER,
    SymbolType::OCTNUMBER, SymbolType::BINNUMBER, SymbolType::HEXNUMBER, SymbolType::ERROR, SymbolType::STRING,
    SymbolType::ERROR, SymbolType::ERROR, SymbolType::ERROR, SymbolType::ERROR, SymbolType::ERROR};

//first: last state   ;     second: halt position
std::pair<int, int> runOnce(std::string input, const int start) {
    int position = start;
//a convenient macro
#define getipt() ((position < input.length()) ? (char_mapping[input.at(position)]) : (12))
    int state = 0;
    int last_state;
    while ((state >= 0) && (position <= input.length())) {
        last_state = state; //save last state
        state = transMatrix[state][getipt()]; //update the state
        position ++;
    }
    return std::make_pair(last_state, position - 1); //start - 1 = halt position
#undef getipt
}

std::vector<Token> lex(std::string input) {
    int position = 0;
    std::vector<Token> tokens; //tokens
    while (position < input.length()) {
        auto result = runOnce(input, position); //run the automata
        assert(result.first >= 0);
        if (result.second > position) //if moved
            tokens.push_back({state2type[result.first], input.substr(position, result.second - position)});
        position = (position + 1) > result.second ? (position + 1) : result.second; //move at least 1 character
    }
    return tokens;
}