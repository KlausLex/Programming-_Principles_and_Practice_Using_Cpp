#include "../../std_lib_facilities.h"

class Token {               // a very simple user-defined type
public:
    char kind;
    double value;
};

int main(){
    Token t1 {'+'};         // initialize t1 so that t1.kind = '+'
    Token t2 {'8', 11.5};   // initialize t2 so that t2.kind = '8' and t2.value = 11.5
    cout << "t1.kind is: " << t1.kind << "\n";
    cout << "t2.kind is: " << t2.kind << "\n";
    cout << "t2.value is: " << t2.value << "\n";
};