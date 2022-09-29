#include "../../std_lib_facilities.h"

int main(){
    constexpr double krona_per_pound = 12.19;   // amount of swedish krona worth one british pound
    constexpr double krona_per_yen = 0.078;     // amound of swedish krona worth one japanese yen
    constexpr double yen_per_krona = 12.74;     // amount of japanese yen worth one swedish krona
    constexpr double yen_per_pound = 155.81;    // amount of japanese yen worth one british pound
    constexpr double pounds_per_krona = 0.082;  // amount of british pounds worth one swedish krona
    constexpr double pounds_per_yen = 0.0064;   // amount of british pounds worth one japanese yen

    double amount = 1;                          // amount in yen, pounds
    char unit_from = ' ';                       // a space is not a unit
    char unit_to = ' ';                     

    cout<< "Please enter an amount of money followed by its currency to convert from, followed by the currency to convert it to (k = krona, y = yen or p = pounds):\n";
    cin >> amount >> unit_from >> unit_to;

    if (unit_from == 'y')
        if (unit_to == 'k')
            cout << amount << "yen == " << yen_per_krona * amount << "krona\n";
        else if (unit_to == 'p')
        cout << amount << "yen == " << amount / cm_per_inch << "pounds\n";
    else if (unit_from == 'k')
        if (unit_to == 'p')
            cout << amount << "krona == " << yen_per_krona << "pounds\n";
        else if (unit to == 'y')
            count << amount << "krona == " << yen_per_krona << "yen\n";
    else if (unit from == 'p')
        if (unit_to == 'k')
            cout << amount << "pounds == " << pounds_per_krona << "krona\n";
        else if (unit_to == 'y')
            cout << amount << "pounds == " << yen_per_pounds << "yen\n";
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
}