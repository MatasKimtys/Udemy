/*----------------------------------------
 * Author: Matas Kimtys
 * Contents: Student code and notes were made while learning from Udemy course on C++ beginner-intermediate level
 * --------------------------------------*/

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <climits>
#include <cmath>

using namespace std;
using namespace std::this_thread; //sleep_for, sleep_until
using namespace std::chrono_literals; //ns, us, ms, s, h, etc.
using std::chrono::system_clock;

//--declare functions--
void printOverTime();
void Clear();
int throwADice();
string throwAlotOfDice();
void calculateAreaOfRoom();
void integer_types();
void float_point_types();
void check();
void testingCLimits();
void makingAndTestingConstants();
void fleetServices();
void yesOrNo();
void characterFunctions();
void CStyleStrings();
void CPPString();
//---------------------

//--declare global variables--
string itp;
int dice;
//---------------------

int main() {
    /*

    itp = "Hello, welcome to my learning process of C plus plus. Enjoy. \n\n";
    printOverTime();
    srand(time(NULL)); //seeding for the first time only!
    cout << "Let's throw two dice. We got " + to_string(throwADice());
    cout << " and " + to_string(throwADice()) << endl;
    itp = throwAlotOfDice();
    printOverTime();
    calculateAreaOfRoom();
    integer_types();
    float_point_types();
    check();
    testingCLimits();
    makingAndTestingConstants();
    fleetServices();
    characterFunctions();
    CStyleStrings();
    */
    CPPString();
    return 0;
}

// generate a 1random number between 1 and 6
int throwADice() {
    return rand() % (6 + 1);
}

string throwAlotOfDice() {
    itp = "Let's throw a lot of dice: ";
    int i = 0;
    int n = 10;
    while (i < n) {
        itp = itp + to_string(rand() % (6 + 1));
        if (i == n - 1)
        {
            itp = itp + ".";
        }
        else
        {
            itp = itp + ", ";
        }
        ++i;
    }
    return itp;
}

void printOverTime()
{
    for (long long unsigned int i = 0; i < itp.length(); ++i) {
        std::cout << itp[i];
        sleep_for(2ns);
        sleep_until(system_clock::now() + 4ms);
    }
    sleep_for(100ms);
}

void Clear()
{

#if defined _WIN32
    system("cls");
#endif

}

void calculateAreaOfRoom() {
    double _width;
    double _length;
    cout << "\nEnter the width and length of your room seperated by a space: ";
    cin >> _width >> _length;
    double _result = _width * _length;
    cout << "\nAwesome, your room sqm: " << _width << " * " << _length << " = " << _result << "m^2." << endl;

}

void integer_types() {
    unsigned short int some_number_v1{ 26 };
    int some_number_v2{ 1 };
    long some_number_v3{ 192122222 };
    long long some_number_v4{ 1'000'000'000 };
    long long some_number_v5{ 9'123'123'123'123 };
    cout << "\n" << some_number_v1 << ", " << some_number_v2 << ", " << some_number_v3 << ", " << some_number_v4 << ", " << some_number_v5;
}

void float_point_types() {
    float some_float_v1{ 123.45 };
    double pi{ 3.14159 };
    long double some_large_float_v1{ 1.4e120 };

    cout << "\n" << some_float_v1 << ", " << pi << ", " << some_large_float_v1;
}

void check() {
    bool is_what{ true };
    string result = "";
    if (is_what) {
        result = "true";
    }
    else {
        result = "false";
    }
    cout << "\nThese numbers are " << result << ", because they are more than 0";
}

void testingCLimits() {
    cout << "\n\n-----sizeof variabletype tests------" << endl;
    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int: " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes." << endl;
    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." << endl;
    cout << "-----end of variable type tests------" << endl;

    cout << "\n\n--values defined within <climits> standard library--" << endl;
    cout << "\n -MIN-" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;

    cout << "\n -MAX-" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;
    cout << "-----end of value tests----------" << endl;
    unsigned short int some_number_v1{ 26 };
    cout << "v1: " << sizeof(some_number_v1) << endl;
    int some_number_v2{ 1 };
    cout << "v2: " << sizeof(some_number_v2) << endl;
    long some_number_v3{ 192122222 };
    cout << "v3: " << sizeof(some_number_v3) << endl;
    long long some_number_v4{ 1'000'000'000 };
    cout << "v4: " << sizeof(some_number_v4) << endl;
    long long some_number_v5{ 9'123'123'123'123 };
    cout << "v5: " << sizeof(some_number_v5) << endl;

}

void makingAndTestingConstants() {
    //literal contants
    int _x = 12; //int
    _x = 12U; // an unsigned int
    _x = 12L; // a long integer
    _x = 12LL; // a long long integer
    double _y = 1.56;
    _y = 1.56F; // a float
    _y = 1.56L; // a long double
    string _name = "Matas";
    char _initial = 'M';
    cout << "\nVartypes out: " << _x << _y << _name << _initial << endl;

    //character literal constant (escape codes)
    // \n new line
    // \r returm
    // \t tab
    // \b backspace
    // \' single quote
    // \" double quote
    // \\ backslash
    cout << "I\tam\ntesting\bliteral\'constants\"" << endl;

    //declaring constants
    const double _size_of_earth{ 196936994.0 };
    cout << "Size of mother Earth: " << _size_of_earth << endl;

#define _some_pi 3.1415926 //NOT TO USE IN MODERN C++
}

void yesOrNo() {
    bool check = false;
    string _user_input;
    while (check == false) {
        cout << "\n\nWould you like to clear previous data? (Enter Yes or No capital sensitive)";
        cin >> _user_input;
        if (_user_input == "Yes") {
            Clear();
            check = true;
        }
        else if (_user_input == "No") {
            cout << "\n\n";
            check = true;
        }
        else {
            cout << "I do not understand, Yes or No?";
        }
    }
}


/*--------Space fleet rental services--------
 * Charge per ship �120000
 * Ship tax 40%
 * Valid for 30 days
 *
 * Number of ships: 41
 * Price per ship: �120000
 * All Ship cost: �4920000
 * Tax cost: �1968000
 *
 * Total estimated cost: 6888000
--------------pseudocode---------------------------
 * Prompt user for number of ships required to be rented like so:
 * Display number of ships available
 * Display price per ship
 * Display ships to rent
 * Display cost (number of ships * price per ship)
 * Display tax (number of ships * price per ship * tax rate)
 * Display total estimated cost ((number of ships * price per ship) + (number of ships * price per ship * tax rate))
 * Display expiry time.
 * */
void fleetServices() {
    const int _ship_cost = 120000;
    const double _tax = 0.4;
    const int _ships_available_to_rent = 16092;
    const int _expiry_time = 30;
    unsigned int _ships_to_rent;
    bool _live = true;
    string _confirmation;
    yesOrNo();
    itp = "Greetings Commander. Welcome to Space Fleet rental services.";
    printOverTime();
    while (_live) {
        itp = "\n\nShips currently available: " + to_string(_ships_available_to_rent);
        printOverTime();
        itp = "\nPrice per ship: " + to_string(_ship_cost) + " Scredits";
        printOverTime();
        itp = "\nCurrent Tax rate: " + to_string((long long int) round(_tax * 100)) + "%";
        printOverTime();
        itp = "\nTotal Estimated cost per ship: " + to_string((long long int) round(_ship_cost + (_ship_cost * _tax))) + " Scredits";
        printOverTime();


        itp = "\n\nHow many ships would you like to rent?";
        printOverTime();
        itp = "\nEnter the number of ships you would like to rent: ";
        printOverTime();
        cin >> _ships_to_rent;
        if (_ships_available_to_rent > _ships_to_rent) {
            itp = "Just in range, we are able to rent this amount of ships.";
            printOverTime();
            sleep_for(1.5s);
            Clear();
        }
        else {
            itp = "Unfortunately, we are only able to rent up to " + to_string(_ships_available_to_rent) + " at the moment.";
            printOverTime();
            itp = "\nEnter the number of ships you would like to rent: ";
            printOverTime();
            cin >> _ships_to_rent;
            if (_ships_to_rent > _ships_available_to_rent) {
                itp = "We are not going to repeat ourselves, have a nice day.";
                printOverTime();
                sleep_for(1s);
                Clear();
                _live = false;
            }
        }
        itp = "\nShips currently available: " + to_string(_ships_available_to_rent);
        printOverTime();
        itp = "\nPrice per ship: " + to_string(_ship_cost) + " Scredits";
        printOverTime();
        itp = "\nShips to rent: " + to_string(_ships_to_rent);
        printOverTime();
        itp = "\nCost: " + to_string((long long int)(_ships_to_rent * _ship_cost)) + " Scredits";
        printOverTime();
        itp = "\nTax: " + to_string((long long int)(_ships_to_rent * _ship_cost * _tax)) + " Scredits";
        printOverTime();
        itp = "\nTotal estimated cost: " + to_string((long long int)(_ships_to_rent * _ship_cost) + (long long int)(_ships_to_rent * _ship_cost * _tax)) + " Scredits";
        printOverTime();
        itp = "\nContract expires in " + to_string(_expiry_time) + " days once confirmed.";
        printOverTime();
        sleep_for(1s);
        itp = "\n\nConfirm you wish to proceed with this service? (Yes/No) ";
        printOverTime();
        cin >> _confirmation;

        if (_confirmation == "Yes") {
            itp = "\nThank you for using our services, i hope our ships serve you well, and do visit us again valued customer.\n\n\n";
            printOverTime();
            sleep_for(3s);
            _live = false;
        }
        else {
            itp = "\nI understand, sometimes the price is too much, we are all suffering from inflation. \nWould you like to try our services again? ";
            printOverTime();
            cin >> _confirmation;
            if (_confirmation == "Yes") {
                Clear();
            }
            else {
                itp = "Oh well, you have a nice day then.\n\n\n";
                printOverTime();
                sleep_for(2s);
                _live = false;
            }
        }
    }
}

void arrayLesson() {

}

void IncrDecrOperator() {
    Clear();

}

void characterFunctions() {
    vector<char> list;
    list.push_back('a');
    list.push_back('B');
    list.push_back('3');
    list.push_back('d');
    list.push_back('e');
    list.push_back(',');
    list.push_back('A');
    list.push_back(' ');

    int alpha{ 0 };
    int alnum{ 0 };
    int digit{ 0 };
    int lower{ 0 };
    int print{ 0 };
    int punct{ 0 };
    int upper{ 0 };
    int space{ 0 };

    for (char list_element : list) {
        if (isalpha(list_element)) alpha++; // is letter
        if (isalnum(list_element)) alnum++; // is letter is a digit
        if (isdigit(list_element)) digit++; // is digit
        if (islower(list_element)) lower++; // is lowercase
        if (isprint(list_element)) print++; // is printable
        if (ispunct(list_element)) punct++; // is punctuation character
        if (isupper(list_element)) upper++; // is uppercare
        if (isspace(list_element)) space++; // is whitespace
    }
    printf("%d %d %d %d %d %d %d %d", alpha, alnum, digit, lower, print, punct, upper, space);

    tolower(list.at(1));
    toupper(list.at(0));


}

void CStyleStrings() {
    char str[100];
    strcpy_s(str, "Greetings"); //copy
    strcat_s(str, "there.");  //concatenate
    cout << strlen(str); //15
    cout << "\n" << strcmp(str, "Another"); // > 0

    char first_name[20];

    char last_name[20];
    char full_name[20];
    char temp[20];
    sleep_for(1s);
    Clear();
    /*
    cout << "Enter your first name: ";
    cin >> first_name ;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "\n";

    strcpy_s(full_name, first_name);
    strcat_s(full_name, " ");
    strcat_s(full_name, last_name);
    sleep_for(100ms);
    Clear();
    */

    cout << "Enter your full name: ";
    cin.getline(full_name, 50);
    Clear();
    cout << "Your full name is: " << full_name << "\n";

    sleep_for(1s);
    Clear();

    strcpy_s(temp, full_name);
    if (strcmp(temp, full_name) == 0) {
        cout << "Comparison says they are the same\n";
    }
    else {
        cout << "Comparison says they are not the same\n";
    }

    sleep_for(1s);
    Clear();

    for (size_t i{ 0 }; i < strlen(full_name); ++i) {
        if (isalpha(full_name[i])) {
            full_name[i] = toupper(full_name[i]);
        }
    }
    cout << "Let's shout your name: " << full_name << "!!!\n";

}

void CPPString() {
    string s1; // empty
    string s2{ "Matas" }; // Matas
    string s3{ "matas" }; // matas
    string s4{ "Matas", 4 }; // Mata
    string s5{ s3, 0, 2 }; // Ma  from index0 to length
    string s6{ 3, 'a' }; // aaa


    for (int i : s2) {
        cout << i << endl; //ascii code for my name characters
    }

    string s7{ "This is some string." };
    cout << s7.substr(0, 6) << endl;
    cout << s7.substr(6, 19) << endl;

    cout << s7.find("string");
    cout << s7.rfind("string");
    s7.erase(s7.find("string"), s7.length()); // erases ..string
    cout << "\n" << s7;
    s7.clear();
    cout << "\n" << s7;


    string s8(10, 'A');
    sleep_for(1s);
    Clear();
    cout << boolalpha;
    cout << s2 << " == " << s2 << ": " << (s2 == s2) << endl;
    cout << s2 << " == " << s3 << ": " << (s2 == s3) << endl;
    cout << s2 << " != " << s3 << ": " << (s2 != s3) << endl;
    cout << "apple" << " < " << "Apple" << ": " << ("apple" < "Apple") << endl;
    cout << "apple" << " > " << "Apple" << ": " << ("apple" > "Apple") << endl;


    sleep_for(1s);
    Clear();
    string word{};
    string sentence{ "The cosmos is boundless!" };
    cout << "Let's find a word. Enter the word to find: ";
    cin >> word;
    size_t position = sentence.find(word);
    if (position != string::npos) {
        cout << "Found " << word << " at position: " << position << endl;
    }
    else {
        cout << "Word does not exist." << endl;
    }
    sleep_for(1s);
    Clear();
    //test 1
    string unformatted_full_name{ "StephenHawking" };

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    string first_name{ "" };
    string last_name{ "" };
    int fn_i{ -1 };
    int ln_i{ -1 };
    int i = 0;
    for (char c : unformatted_full_name) {
        if (isupper(c) && fn_i == -1) {
            fn_i = i;
        }
        else if (isupper(c) && ln_i == -1) {
            ln_i = i;
        }
        ++i;
    }
    first_name = unformatted_full_name.substr(fn_i, ln_i);
    last_name = unformatted_full_name.substr(ln_i, unformatted_full_name.length() - 1);

    string formatted_full_name = first_name + " " + last_name;

    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----

    cout << formatted_full_name;

}