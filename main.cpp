#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>

using namespace std;
using namespace std::this_thread; //sleep_for, sleep_until
using namespace std::chrono_literals; //ns, us, ms, s, h, etc.
using std::chrono::system_clock;

void printOverTime();
void Clear();
int throwADice();
string throwAlotOfDice();
void calculateAreaOfRoom();


string itp;
int dice;

int main() {
    itp = "Hello, welcome to my learning process of C plus plus. Enjoy. \n\n";
    printOverTime();
    srand(time(NULL)); //seeding for the first time only!
    cout << "Let's throw two dice. We got " + to_string(throwADice());
    cout << " and " + to_string(throwADice()) << endl;
    itp = throwAlotOfDice();
    printOverTime();
    calculateAreaOfRoom();
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
    while(i<n){
        itp = itp + to_string(rand() % (6 + 1));
        if(i == n-1)
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
    for (int i = 0; i < itp.length(); ++i) {
        std::cout << itp[i];
        sleep_for(2ns);
        sleep_until(system_clock::now() + 5ms);
    }
}

void Clear()
{
    
#if defined _WIN32
    system("cls");
#endif

}

void calculateAreaOfRoom(){
    double _width;
    double _length;
    cout << "\nEnter the width and length of your room seperated by a space: ";
    cin >> _width >> _length;
    double _result = _width * _length;
    cout << "\nAwesome, your room sqm: " << _width << " * " <<_length << " = " << _result <<"m^2." << endl;
    
}