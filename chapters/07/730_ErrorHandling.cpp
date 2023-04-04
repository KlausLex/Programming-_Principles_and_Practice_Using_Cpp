#include "../../std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

Token get_token();              // function to read a token from cin

vector <Token>tok;              // we'll put the token here

class Token_stream {
public:
    Token get();                // get a Token
    void putback(Token t);      // put a Token back
private:
    bool full {false};          // is there a Token in the buffer?
    Token buffer;               // here is where we kep a Token put back using putback()
};

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
}

Token Token_stream::get()
{
    if (full) {                 // do we already have a Token ready?
        full = false;           // remove Token from buffer
        return buffer;
    }
    char ch;
    cin >> ch;                  // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':                   // for "print"
    case 'q':                   // for "quit"
    case '(': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);        // put digit back into the input stream
        double val;
        cin >> val;             // read a floating-point number
        return Token{'8', val}; // let '8' represent " a number"
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;                // a Token_stream called ts
Token t = ts.get();             // gt next Token from ts
// . . . 
ts.putback(t);                  // put the Token t back into ts

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

double term()
{
    double left = primary();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {   double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = get_token();
            break;
        }
        default:
            return left;
        }
    }
}

int main()
try
{
    while (cin) {
        cout << ">";
        Token t = ts.get();
        while (t.kind == ';') t = ts.get();         // eat ';'
        if (t.kind == 'q') {
            keep_window_open();
            return 0;
        }
        ts.putback(t);
        cout << "= " << expression() << '\n';
    }
    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}

