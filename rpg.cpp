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
#include "Monster.h"
#include "Player.h"
#include "Weapon.h"

using namespace std;
using namespace std::this_thread; //sleep_for, sleep_until
using namespace std::chrono_literals; //ns, us, ms, s, h, etc.
using std::chrono::system_clock;

//initialise functions
Monster createMonster();
Weapon createWeapon();
Player createPlayer();
Monster attackMonster();
Monster monsterThread();
Player playerThread();
//initialise global variables
bool _playing = false;
bool _lobby = false;
bool __player_stats = false;
bool _duel = false;

string _action;

int main() {
    srand(time(NULL));
    Monster _monster = createMonster();
    Player _player = createPlayer();
    std::thread _m(monsterThread());
    std::thread _p(playerThread());
    _playing = true;
    while (_playing) {
        _lobby = true;
        while (_lobby) {
            cout << "What now? Actions: (player stats/duel/quit) ";
            cin >> _action;
            if (_action == "player stats") {

            }
            else if (_action == "duel") {
                sleep_for(500ms);
                _duel = true;
                _lobby = false;
            }
            else if (_action == "quit") {
                _lobby = false;
                _playing = false;
            }
            else {
                cout << "I dont understand. Type (player stats OR duel)";
                sleep_for(1500ms);
                Clear();
            }
        }

        while (_duel) {
            while (_monster._monster_health > 0 && _player._player_health > 0) {

                sleep_for(10ms);
            }
        }

    }

    return 0;
}

void monsterThread(Monster _input_monster) {
    while (_input_monster._monster_health > 0) {

    }
}

void playerThread(Player _input_player) {
    while (_input_player._player_health > 0) {

    }
}


Monster createMonster() {
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

    _monster_to_create._monster_name = __random_names.at(_random_number);
    _monster_to_create._monster_level = rand() % (100 - 1 + 1) + 1;
    _monster_to_create._monster_atk_min = rand() % (_monster_to_create._monster_level / 2 - 1 + 1) + 1;
    _monster_to_create._monster_atk_max = rand() % (_monster_to_create._monster_level * 2 - _monster_to_create._monster_atk_min + 1) + _monster_to_create._monster_atk_min;
    _monster_to_create._monster_health = rand() % (_monster_to_create._monster_level * 10 - _monster_to_create._monster_level * 5 + 1) + _monster_to_create._monster_level * 5;
    _monster_to_create._monster_evasion = rand() % (_monster_to_create._monster_level - 0 + 1) + 0;
    _monster_to_create._monster_evasion_rate = _monster_to_create._monster_evasion / 10;
    _monster_to_create._monster_defence = _monster_to_create._monster_level - (_monster_to_create._monster_level / 10);
    _monster_to_create._monster_damage_reduction_rate = _monster_to_create._monster_level / 10;
    _monster_to_create._monster_experience_reward = rand() % (_monster_to_create._monster_level * 2 - _monster_to_create._monster_level / 2 + 1) + _monster_to_create._monster_level / 2;
    return _monster_to_create;
}

Weapon createWeapon() {
    Weapon _weapon;
    std::vector<std::string> __material =
    {
        "Wooden", "Steel", "Gold", "Platinum", "Obsidian", "Plaglass"
    };
    std::vector<std::string> __weapon_names =
    {
        "Cestus", "Longsword", "Warhammer", "Bow", "Crossbow", "War Axe", "Rod"
    };

    int _random1 = rand() % (__material.size() - 0 + 1) + 0;
    int _random2 = rand() % (__weapon_names.size() - 0 + 1) + 0;

    _weapon._weapon_name = __material.at(_random1) + __weapon_names.at(_random2);
    _weapon._weapon_accuracy = 70;
    _weapon._weapon_description = "It's a weapon.";
    _weapon._weapon_durability = 100;
    _weapon._weapon_physical_atk_min = 10;
    _weapon._weapon_physical_atk_max = 30;
    _weapon._weapon_magic_atk_min = 10;
    _weapon._weapon_magic_atk_max = 30;
    _weapon._weapon_enchancement_level = 0;

    return _weapon;
}

Player createPlayer() {
    Player _player;
    cout << "Whats your name: ";
    cin >> _player._player_name;
    _player._player_level = 1;
    _player._player_health = 100;
    _player._player_stamina = 100;
    _player._player_mana = 100;
    _player._player_exp = 0;
    _player._equipped_weapon = createWeapon();

    return _player;
}

void Clear()
{

#if defined _WIN32
    system("cls");
#endif

}

