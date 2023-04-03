#include "../../std_lib_facilities.h"

double primary()
{
    Token t = get_token();
    switch (t.kind) {
    case '(':                       // handle '(' expression ')'
        {   double d = expression();
            t = get_token();
            if (t.kind != ')') error ("')' expected");
        }
    case '8':                       // we use '8' to represent a number
        return t.value;             // return the number's value
    default:
        error("primary expected");
    }
}