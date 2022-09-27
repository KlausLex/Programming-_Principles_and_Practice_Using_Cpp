#include "../../std_facilities.h"

int main(){
    constexpr double cm_per_inch = 2.54;    // number of centimeters in an inch
    constexpr double yen_per_krona = 12.74;     // number of yen worth one krona
    constexpr double pounds_per_krona = 0.082;  // number of pounds worth one krona

    double length = 1;                      // length in inches or centimeters
    char unit = ' ';                        // a space is not a unit

    cout<< "Please enter an amount of krona followed by a unit to convert (y=yen or p=pounds):\n"; cin >> length >> unit;

    if (unit == 'y')
        cout << length << "in == " << cm_per_inch*length << "yen\n";
    else if (unit == 'p')
        cout << length << "cm == " << length/cm_per_inch << "pounds\n";
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
}