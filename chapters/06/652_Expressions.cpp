#include "../../std_lib_facilities.h"

double expression()
{
    double left = term();           // read and evaluate a Term
    Token t = get_token();          // get the next token
    switch (t.kind) {               // see which kind of token that is
    case '+':
        return left + expression(); // read and evaluate an Expression,
                                    // then do an add
    case '-':
        return left - expression(); // read and evaluate an Expression,
                                    // then do a subtraction
    default:
        return left;                // return the valua of the Term
    }
}
