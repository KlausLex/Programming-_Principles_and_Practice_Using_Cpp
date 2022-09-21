#include "../../std_lib_facilities.h"
int main()
{
    // 01
    cout << "Enter your name:" << '\n';
    string my_name;  // First name
    cin >> my_name;  // get first name from user input
    cout << "Hello " << my_name << '\n';
    cout << "Enter the name of the person you want to write to: " << '\n';
    string first_name;
    cin >> first_name;  // get the other person's name
    cout << '\n' << '\n' << "Dear " << first_name << "," << '\n';

    // 02
    cout << "   How are you? I hope you're fine" << '\n' << "   How long has it been? Must be ages!" << '\n' << "   Talk to you soon!" << '\n';
    
    // 03
    cout << "   Enter the name of another friend: " << '\n';
    string friend_name;
    cin >> friend_name;
    cout << "   Have you seen " << friend_name << " lately?" << '\n';

    // 04
    char friend_sex = 0;
    cout << "   Enter [m] if your friend is male or [f] if your friend is female" << '\n';
    cin >> friend_sex;

    if (friend_sex == 'm'){
        cout << "   If you see " << friend_name << ", please ask him to call me." << '\n';
    }
    if (friend_sex == 'f'){
        cout << "   If you see " << friend_name << ", please ask her to call me." << '\n';
    }

    // 05
    cout << "   How old is " << friend_name << "?" << '\n';
    int age;
    cin >> age;
    cout << "   I hear you just had a birthday and you are " << age << " years old." << '\n';

    if (age <= 0 | age >= 110){
        simple_error("You're kidding!");
    }

    // 06
    if (age < 12){
        cout << "   Next year you will be " << age + 1 << "." << '\n';
    }
    if (age == 17){
        cout << "   Next year you will be able to vote." << '\n';
    }
    if (age > 70){
        cout << "   I hope you are enjoying retirement." << '\n';
    }

    // 07
    cout << "   Yours sincerely, " << '\n' << '\n' << '\n' << my_name << '\n';
}