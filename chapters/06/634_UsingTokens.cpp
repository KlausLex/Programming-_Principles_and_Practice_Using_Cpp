#include "../../std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

Token get_token();              // function to read a token from cin

vector <Token>tok;              // we'll put the token here

int main()
{
    while (cin){
        Token t = get_token();
        tok.push_back(t);
    }
    // . . .
    for (int i = 0; i<tok.size(); ++i){
        if (tok[i].kind=='*'){   // w found a multiply!
            double d = tok[i-1].value*tok[i+1].value;
            // now what
        }
    }
    //cout << "product d is: " << d;
}
