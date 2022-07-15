/*--------------------------
Author: Matas Kimtys
A simple rpg example.

Task:
add button listeners to console
depending on pressed button, information of monster, player should be displayed seperately. 
make an attack button. 

information of monster should consist of name, level, atk_min, atk_max, health, evasion, defence, defence rate.
information of player should consist of level, atk_min, atk_max, health, evasion, defence, defence rate. 
-------------------------*/
//https://github.com/MatasKimtys/Portfolio.git

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>

//initialise functions
// 
//initialise global variables
bool _playing = true;
int main(){
    srand(time(NULL));
    Monster* _object = new Monster();
    std::cout << _object->_monster_name;
    return 0;
}

class Monster {
public:
    std::string _monster_name = ""; //0
    int _monster_level; //1
    int _monster_atk_min; //2
    int _monster_atk_max; //3
    int _monster_health; //4 
    int _monster_evasion; //5
    int _monster_evasion_rate; //6
    int _monster_defence; //7 
    int _monster_damage_reduction_rate; //8

    Monster() {
        Monster _monster_to_create;
        std::vector<std::string> __random_names =
        {
            "Babirusa",
            "Baboon",
            "Bactrian Camel",
            "Badger",
            "Baird’s Rat Snake",
            "Bald Eagle",
            "Baleen Whale",
            "Balinese",
            "Balkan Lynx",
            "Ball Python"
        };
        int _random_number = rand() % (__random_names.size() - 0 + 1) + 0;
        std::string _random_name = __random_names.at(_random_number); // pick a random name from list of monster name list


        _monster_to_create._monster_name = _random_name;
        _monster_to_create._monster_level = rand() % (100 - 1 + 1) + 1;
        _monster_to_create._monster_atk_min = rand() % (_monster_to_create._monster_level / 2 - 1 + 1) + 1;
        _monster_to_create._monster_atk_max = rand() % (_monster_to_create._monster_level * 2 - _monster_to_create._monster_atk_min + 1) + _monster_to_create._monster_atk_min;
        _monster_to_create._monster_health = rand() % (_monster_to_create._monster_level * 10 - _monster_to_create._monster_level * 5 + 1) + _monster_to_create._monster_level * 5;
        _monster_to_create._monster_evasion = rand() % (_monster_to_create._monster_level - 0 + 1) + 0;
        _monster_to_create._monster_evasion_rate = _monster_to_create._monster_evasion / 10;
        _monster_to_create._monster_defence = _monster_to_create._monster_level - (_monster_to_create._monster_level / 10);
        _monster_to_create._monster_damage_reduction_rate = _monster_to_create._monster_level / 10;
    }
};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
