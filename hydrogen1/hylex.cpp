#include <hylex.h>


namespace hydrogen {
    
    Lexer::Lexer(std::istream &input) 
        : input(input)
    {
    }

    Lexer::~Lexer() {
    }


    std::string ToString(Token::TokenType type) {
        switch(type){
        case Token::DecNumber:{
            return "DecNumber";
        }
        case Token::HexNumber:{
            return "HexNumber";
        }
        case Token::OctNumber:{
            return "OctNumber";
        }
        case Token::BinNumber:{
            return "BinNumber";
        }
        case Token::Identifier:{
            return "Identifier";
        }
        case Token::String:{
            return "String";
        }
        case Token::Error :{
            return "Error";
        }
        default: {
            return "Unknown";
        }
        }
    }
 
    Token Lexer::DecNumber() {
        std::string value = "";
        value += input.get();

        char ch = input.peek();
        while (ch >= '0' && ch <= '9') {
            value += ch;
            input.get();
            ch = input.peek();
        }
        return Token{Token::DecNumber, value};
    }

    Token Lexer::HexNumber() {
        std::string value = "";
        value += input.get();
        value += input.get(); //读取开头的0x

        char ch = input.peek();

        if (! ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
            return Token{Token::Error, "error"};
        }

        while ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            value += ch;
            input.get();
            ch = input.peek();
        }
        return Token{Token::HexNumber, value};
    }

    Token Lexer::OctNumber() {
        std::string value = "";
        value += input.get();
        value += input.get(); //其实可以再读取一个的 因为在Number里我们前两个都验证过了

        char ch = input.peek();

        while (ch >= '0' && ch <= '7') {
            value += ch;
            input.get();
            ch = input.peek();
        }
        return Token{Token::OctNumber, value};

    }

    Token Lexer::BinNumber() {
        std::string value = "";
        value += input.get();
        value += input.get(); //读取开头的0b

        char ch = input.peek();

        if (! (ch >= '0' && ch <= '1')) {
            return Token{Token::Error, "error"};
        }

        while (ch >= '0' && ch <= '1') {
            value += ch;
            input.get();
            ch = input.peek();
        }
        return Token{Token::BinNumber, value};
    }

    Token Lexer::Number() {
        char ch_zero = input.get();
        char ch = input.peek();
        input.putback(ch_zero);
        
        if (ch == 'x' || ch == 'X') {
            return HexNumber();
        }
        if (ch >= '0' && ch <= '7') {
            return OctNumber();
        }
        if (ch == 'b' || ch == 'B') {
            return BinNumber();
        }
        return DecNumber();
    }

    Token Lexer::LexOnce() {
        char ch = input.peek();
        if (ch >= '1' && ch <= '9') {
            return DecNumber();
        }
        if (ch == '0') {
            return Number();
        }
        return Token{Token::Error, "error"};
    }

    std::vector<Token> Lexer::Lex() {
        std::vector<Token> tokens;


        while (true) {
            
        }

        return tokens;
    }
}