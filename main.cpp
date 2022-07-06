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
//---------------------

//--declare global variables--
string itp;
int dice;
//---------------------

int main() {
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
 * Charge per ship £120000
 * Ship tax 40%
 * Valid for 30 days
 *
 * Number of ships: 41
 * Price per ship: £120000
 * All Ship cost: £4920000
 * Tax cost: £1968000
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