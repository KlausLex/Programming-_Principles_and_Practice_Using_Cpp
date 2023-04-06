#include "../../std_lib_facilities.h"


/*
    Simple calculator
    
    Revision history:
    
        Revised by Bjarne Stroustrup November 2013
        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Original written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.
            
        This program implements a basic expression calculator.
        Input from cin; output to cout.
        The gramar for input is:
        
        Statement:
            Expression
            Print
            Quit
            
        Print:
            ;
        
        Quit:
            q
        
        Expression:
            Term
            Expression + Term
            Expression - Term
            
        Term:
            Primary
            Term * Primary
            Term / Primary
            Term % Primary
            
        Primary:
            Number
            ( Expresion )
            - Primary
            + Primary
        
        Number:
            floating-point literal
            
        Input comes from cin through the Token_stream called ts.
    */

const char number = '8';
const char quit = 'q';      // t.kind==quit means that t is a quit Token
const char print = ';';     // t.kind==prnt means that t is a print Token
const string prompt = "> ";
const string result = "= "; // used to indicate that what follows is a result


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
    // read characters from cin and compose a Token
{
    if (full) { // check if we already have a Token ready
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;  // note that << skips whitespace (space, newline, tab, etc)

    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token(ch);   // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':   // numeric literal
    {
        cin.putback(ch);    // put digit back into the input stream
        double val;
        cin >> val;         // read a floating-point number
        return Token(number,val);
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
    Token t = ts.get();
    switch (t.kind) {
    case '(':                            // handle ‘(’ expression ‘)’
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case 'number':                           // we use '8' to represent a number
        return t.value;
    case '-':
        return - primary();
    case '+':
        return primary();
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
        case '%':
        {
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(primary());
            if (i2 == 0) error("%: divide by zero");
            left = i1%i2;
            t = ts.get();
            break;
        }
        default:
            return left;
        }
    }
}

void calculate()            // expression evaluation loop
{
    while (cin) {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();         // first discard all "prints"
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << expression() << '\n';
    }
}


int main()
try
{
    calculate();
    keep_window_open();             // cope with Windows console mode
    return 0;
}
catch (runtime_error& e) {
    cerr << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}

catch (. . .) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

