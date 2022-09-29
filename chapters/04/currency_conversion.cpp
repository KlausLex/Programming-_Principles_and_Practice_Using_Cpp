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

    // from japanese yen..
    if (unit_from == 'y'){
        // ..to swedish krona
        if (unit_to == 'k'){
            cout << amount << " yen == " << yen_per_krona * amount << " krona\n";
        }
        // ..to british pounds
        else if (unit_to == 'p'){
            cout << amount << " yen == " << yen_per_pound << " pounds\n";
        }
        else
            cout << "Sorry, I don't know a unit called '" << unit_to << "'\n";
    }
    // from swedish krona..
    else if (unit_from == 'k'){
        // ..to british pounds
        if (unit_to == 'p'){
            cout << amount << " krona == " << krona_per_pound << " pounds\n";
        }
        // ..to japanese yen
        else if (unit_to == 'y'){
            cout << amount << " krona == " << krona_per_yen << " yen\n";
        }
        else
            cout << "Sorry, I don't know a unit called '" << unit_to << "'\n";
    }
    // from british pounds..
    else if (unit_from == 'p'){
        // ..to swedish krona
        if (unit_to == 'k'){
            cout << amount << " pounds == " << pounds_per_krona << " krona\n";
        }
        // ..to japanese yen
        else if (unit_to == 'y'){
            cout << amount << " pounds == " << yen_per_pound << " yen\n";
        }
        else
            cout << "Sorry, I don't know a unit called '" << unit_to << "'\n";
    }
    // unknow currency
    else
        cout << "Sorry, I don't know a unit called '" << unit_from << "'\n";
}