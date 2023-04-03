#include "../../std_lib_facilities.h"

double term()
{
    double left = primary();
    Token t = get_token();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            left /= primary();
            t = get_token();
            break;
        case '%':
            left %= primary();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}