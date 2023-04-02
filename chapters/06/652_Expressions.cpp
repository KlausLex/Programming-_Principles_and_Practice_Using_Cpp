#include "../../std_lib_facilities.h"

double expression()
{
    double left = term();                   // read and evaluate a Term
    Token t = get_token();                  // get the next token
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();             // evaluate Term and add
                t = get_token();
                break;
            case '-':
                left -= term();             // evaluate Term and subtract
                t = get_token();
                break;
            default:
                return left;                // finally: no more + or -; return the answer
        }
    }
}