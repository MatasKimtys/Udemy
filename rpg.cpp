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
Monster createMonsterRandom();
Monster createMonster(Player _player);
Weapon createWeaponRandom();
Weapon createWeaponCustom(Player _player);
Player createPlayer();
void Clear();
Player shop(Player _player);
void displayPlayerStats(Player _player);
void displayMonsterStats(Monster _monster);
Player levelSystem(Player _player);
Monster attackMonster(Monster _monster, Player _player);
Monster attackMonsterSpecialAttack(Monster _monster, Player _player);
Player attackPlayer(Monster _monster, Player _player);
void death(Player _player);

//initialise global variables
bool _playing = false;
bool _lobby = false;
bool __player_stats = false;
bool _choosing_weapon = true;
bool _duel = false;

string _action;

int main() {
    srand(time(NULL));

    Player _player = createPlayer();
    Clear();

    //std::thread _m(monsterThread());
    //std::thread _p(playerThread());
    _playing = true;
    while (_playing) {
        _lobby = true;
        while (_lobby) {
            displayPlayerStats(_player);
            cout << "\n\nWhat now? Actions: (duel/shop/quit)\n";
            cin >> _action;

            if (_action == "duel") {
                sleep_for(500ms);
                _duel = true;
                _lobby = false;
            }
            else if (_action == "quit") {
                Clear();
                _lobby = false;
                _playing = false;
            }
            else if (_action == "shop") {
                _player = shop(_player);
            }
            else {
                cout << "\n\nI dont understand. Type (duel/shop/quit)";
                sleep_for(1500ms);
                Clear();
            }
        }

        while (_duel) {
            Monster _monster = createMonster(_player);
            while (_monster._monster_health > 0 && _player._player_health > 0) {
                Clear();
                displayPlayerStats(_player);
                displayMonsterStats(_monster);
                cout << "\n\nType \n(f) to swing your weapon\n(s) to use special attack\n\n";
                cin >> _action;
                if (_action == "f") {
                    _monster = attackMonster(_monster, _player);
                    _player = attackPlayer(_monster, _player);
                    sleep_for(2s);
                    death(_player);
                }
                else if (_action == "s") {
                    _monster = attackMonsterSpecialAttack(_monster, _player);
                    _player = attackPlayer(_monster, _player);
                    _player._player_mana -= 20;
                    sleep_for(2s);
                    death(_player);
                }
                else {

                }

            }
            if (_monster._monster_health < 0) {
                int _silver_reward = rand() % ((_monster._monster_level + 10) - 1 + 1) + 1;
                _player._player_silver_coins += _silver_reward;
                _player._player_exp += _monster._monster_experience_reward;
            }

            Clear();
            _player = levelSystem(_player);
            _duel = false;
        }
    }
    return 0;
}

Player shop(Player _player) {
    bool _shopping = true;
    string _choice1 = "";
    string _choice2 = "";
    string _choice3 = "";
    string _choice4 = "";
    int _cost = 0;
    int _health_to_heal = 0;
    int _mana_to_heal = 0;
    while (_shopping) {
        Clear();
        displayPlayerStats(_player);
        cout << "\n\nShopkeeper: Greetings, please browse our wares.";
        cout << "\n\nWeak health potion(10hp) - 5 silver coins";
        cout << "\nMedium health potion(50hp) - 20 silver coins";
        cout << "\nStrong health potion(100hp) - 40 silver coins";
        cout << "\nGreat health potion(250hp) - 90 silver coins";
        cout << "\nBlessed health potion(500hp) - 170 silver coins";
        cout << "\n\nWeak mana potion(10hp) - 5 silver coins";
        cout << "\nMedium mana potion(50hp) - 20 silver coins";
        cout << "\nStrong mana potion(100hp) - 40 silver coins";
        cout << "\nGreat mana potion(250hp) - 90 silver coins";
        cout << "\nBlessed mana potion(500hp) - 170 silver coins";

        cout << "\n\nIf you bought what you need or cannot afford anything here you can always (leave).";
        cout << "\n\nChoice: ";
        cin >> _choice1;
        if (_choice1 == "leave") {
            Clear();
            _shopping = false;
        }
        else {
            if (_choice1 == "Weak") {
                _cost = 5;
                _health_to_heal = 10;
                _mana_to_heal = 10;
            }
            else if (_choice1 == "Medium") {
                _cost = 20;
                _health_to_heal = 50;
                _mana_to_heal = 50;
            }
            else if (_choice1 == "Strong") {
                _cost = 40;
                _health_to_heal = 100;
                _mana_to_heal = 100;
            }
            else if (_choice1 == "Great") {
                _cost = 90;
                _health_to_heal = 250;
                _mana_to_heal = 250;
            }
            else if (_choice1 == "Blessed") {
                _cost = 170;
                _health_to_heal = 500;
                _mana_to_heal = 500;
            }
            cin >> _choice2 >> _choice3;
            if (_choice2 == "health") {
                if (_player._player_silver_coins >= _cost) {
                    _player._player_silver_coins -= _cost;
                    if (_player._player_health + _health_to_heal < _player._player_health_max) {
                        _player._player_health += _health_to_heal;
                    }
                    else {
                        _player._player_health = _player._player_health_max;
                    }
                }
                else {
                    cout << "\n\nNot enough silver.";
                    sleep_for(2s);
                }
            }
            else if (_choice2 == "mana") {
                if (_player._player_silver_coins >= _cost) {
                    _player._player_silver_coins -= _cost;
                    if (_player._player_mana + _mana_to_heal < _player._player_mana_max) {
                        _player._player_mana += _mana_to_heal;
                    }
                    else {
                        _player._player_mana = _player._player_mana_max;
                    }
                }
                else {
                    cout << "\n\nNot enough silver.";
                    sleep_for(2s);
                }
            }
            else {
                cout << "\n\n Shopkeeper: I dont understand.";
                sleep_for(1500ms);
                Clear();
            }
        }
    }

    return _player;
}

void death(Player _player) {
    if (_player._player_health < 0) {
        Clear();
        cout << "You have died, it was a great journey.\n\n";
        sleep_for(3s);
        _lobby = false;
        _duel = false;
        _playing = false;
    }
}

Monster attackMonster(Monster _monster, Player _player) {
    int _rng = rand() % (100 - 1 + 1) + 1;
    if (_rng < _player._equipped_weapon._weapon_accuracy) {
        int _magic_damage = (rand() % (_player._equipped_weapon._weapon_magic_atk_max - _player._equipped_weapon._weapon_magic_atk_min + 1) + _player._equipped_weapon._weapon_magic_atk_min);
        int _physical_damage = (rand() % (_player._equipped_weapon._weapon_magic_atk_max - _player._equipped_weapon._weapon_magic_atk_min + 1) + _player._equipped_weapon._weapon_magic_atk_min);
        _monster._monster_health = _monster._monster_health - (_magic_damage + _physical_damage);
        cout << "\nYou dealt p" << _physical_damage << " and m" << _magic_damage << " damage to " << _monster._monster_name << ".";
    }
    else {
        cout << "\nYou missed your attack.";
    }

    return _monster;
}

Monster attackMonsterSpecialAttack(Monster _monster, Player _player) {
    if (_player._player_mana < 20) {
        cout << "/nYou tried to muster up mana for a special skill and failed, seems theres not enough.";
    }
    else {
        int _rng = rand() % (100 - 1 + 1) + 1;
        if (_rng < _player._equipped_weapon._weapon_accuracy) {
            int _magic_damage = (rand() % (_player._equipped_weapon._weapon_magic_atk_max - _player._equipped_weapon._weapon_magic_atk_min + 1) + _player._equipped_weapon._weapon_magic_atk_min);
            int _physical_damage = (rand() % (_player._equipped_weapon._weapon_magic_atk_max - _player._equipped_weapon._weapon_magic_atk_min + 1) + _player._equipped_weapon._weapon_magic_atk_min);
            _monster._monster_health = _monster._monster_health - (_magic_damage + _physical_damage);
            cout << "\nYou used a special move " << _player._player_special_attack << " which dealt " << _physical_damage * 3 << " and m" << _magic_damage * 3 << " damage to " << _monster._monster_name << ".";
        }
        else {
            cout << "\nYou missed your attack.";
        }
    }




    return _monster;
}

Player attackPlayer(Monster _monster, Player _player) {
    int _rng = rand() % (100 - 1 + 1) + 1;
    if (_rng < _monster._monster_accuracy) {
        int _damage_to_player = rand() % (_monster._monster_atk_max - _monster._monster_atk_min + 1) + _monster._monster_atk_min;
        _player._player_health = _player._player_health - _damage_to_player;
        cout << "\n" << _monster._monster_name << " dealt " << _damage_to_player << " to you.";
    }
    else {
        cout << "\n" << _monster._monster_name << " missed it's attack.";
    }
    return _player;
}

void displayPlayerStats(Player _player) {
    cout << "Name: " << _player._player_name;
    cout << "\nLevel: " << _player._player_level;
    cout << "\nExperience: " << _player._player_exp;
    cout << "\nHealth: " << _player._player_health;
    cout << "\nMana: " << _player._player_mana;
    cout << "\nSilver Coins: " << _player._player_silver_coins;
    cout << "\nEquipped weapon: " << _player._equipped_weapon._weapon_name;
    cout << "\nWeapon attack: " << "p" << (_player._equipped_weapon._weapon_physical_atk_max - (_player._equipped_weapon._weapon_physical_atk_max - _player._equipped_weapon._weapon_physical_atk_min) / 2) << " m" <<
        _player._equipped_weapon._weapon_magic_atk_max - (_player._equipped_weapon._weapon_magic_atk_max - _player._equipped_weapon._weapon_magic_atk_min) / 2;
}

void displayMonsterStats(Monster _monster) {
    cout << "\n\nYou have encountered " << _monster._monster_name << " level " << _monster._monster_level << "." << endl;
    cout << "Health: " << _monster._monster_health << endl;
}

Monster createMonsterRandom() {
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
    _monster_to_create._monster_accuracy = rand() % (100 - 70 + 1) + 70;
    return _monster_to_create;
}

Monster createMonster(Player _player) {
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

    int _random_number = rand() % ((__random_names.size() - 1) - 0 + 1) + 0;

    _monster_to_create._monster_name = __random_names.at(_random_number);
    int _rng = rand() % (12 - 0 + 1) + 0;
    if (_player._player_level < 10) {

        if (_rng < 7) {
            _monster_to_create._monster_level = 1;
        }
        else {
            _monster_to_create._monster_level = _player._player_level + _rng - 6;
        }

    }
    else {
        _monster_to_create._monster_level = _player._player_level + _rng - 6;
    }
    bool _temp_level_adjustment = false;
    if (_monster_to_create._monster_level % 2 == 1) {
        _monster_to_create._monster_level = _monster_to_create._monster_level + 1;
        _temp_level_adjustment = true;
    }

    _monster_to_create._monster_atk_min = rand() % (_monster_to_create._monster_level / 2 - 1 + 1) + 1;
    _monster_to_create._monster_atk_max = rand() % (_monster_to_create._monster_level * 2 - _monster_to_create._monster_atk_min + 1) + _monster_to_create._monster_atk_min;
    _monster_to_create._monster_health = rand() % (_monster_to_create._monster_level * 10 - _monster_to_create._monster_level * 5 + 1) + _monster_to_create._monster_level * 5;
    _monster_to_create._monster_evasion = rand() % (_monster_to_create._monster_level - 0 + 1) + 0;
    _monster_to_create._monster_evasion_rate = _monster_to_create._monster_evasion / 10;
    _monster_to_create._monster_defence = _monster_to_create._monster_level - (_monster_to_create._monster_level / 10);
    _monster_to_create._monster_damage_reduction_rate = _monster_to_create._monster_level / 10;
    _monster_to_create._monster_experience_reward = rand() % (_monster_to_create._monster_level * 2 - _monster_to_create._monster_level / 2 + 1) + _monster_to_create._monster_level / 2;
    _monster_to_create._monster_accuracy = rand() % (100 - 70 + 1) + 70;

    if (_temp_level_adjustment == true) {
        _monster_to_create._monster_level = _monster_to_create._monster_level - 1;
    }
    return _monster_to_create;
}

Weapon createWeaponRandom() {
    Weapon _weapon;
    std::vector<std::string> __material =
    {
        "Wooden", "Iron", "Steel", "Gold", "Mythril", "Adamantium", "Platinum", "Obsidian", "Mortalslayer", "Demonslayer", "Godslayer"
    };
    std::vector<std::string> __weapon_names =
    {
        "Cestus", "Longsword", "Warhammer", "Bow", "Crossbow", "War Axe", "Rod"
    };

    int _random1 = rand() % ((__material.size() - 1) - 0 + 1) + 0;
    int _random2 = rand() % ((__weapon_names.size() - 1) - 0 + 1) + 0;

    _weapon._weapon_name = __material.at(_random1) + " " + __weapon_names.at(_random2);
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

Weapon createWeaponCustom(Player _player) {
    Weapon _weapon;

    std::vector<std::string> __material =
    {
        "Wooden", "Iron", "Steel", "Gold", "Mythril", "Adamantium", "Platinum", "Obsidian", "Mortalslayer", "Demonslayer", "Godslayer"
    };
    std::vector<std::string> __weapon_names =
    {
        "Cestus", "Longsword", "Warhammer", "Bow", "Crossbow", "War Axe", "Rod"
    };
    string _user_choice = "";


    while (_choosing_weapon) {
        Clear();
        cout << "\nPick a weapon of your choice: Cestus, Longsword, Warhammer, Bow, Crossbow, War Axe, Rod.\n";
        cin >> _user_choice;
        for (int i = 0; i < __weapon_names.size(); ++i) {
            if (_user_choice == __weapon_names.at(i)) {
                cout << "\nGood choice.";
                _choosing_weapon = false;
            }
        }
    }

    if (_player._player_level > 0 && _player._player_level <= 10) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 80) {
            _weapon._weapon_material = __material.at(1);
        }
        else {
            _weapon._weapon_material = __material.at(0);
        }
    }
    else if (_player._player_level > 10 && _player._player_level <= 20) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 85) {
            _weapon._weapon_material = __material.at(2);
        }
        else {
            _weapon._weapon_material = __material.at(1);
        }
    }
    else if (_player._player_level > 20 && _player._player_level <= 30) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 90) {
            _weapon._weapon_material = __material.at(3);
        }
        else {
            _weapon._weapon_material = __material.at(2);
        }
    }
    else if (_player._player_level > 30 && _player._player_level <= 40) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 93) {
            _weapon._weapon_material = __material.at(4);
        }
        else {
            _weapon._weapon_material = __material.at(3);
        }
    }
    else if (_player._player_level > 40 && _player._player_level <= 50) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 95) {
            _weapon._weapon_material = __material.at(5);
        }
        else {
            _weapon._weapon_material = __material.at(4);
        }
    }
    else if (_player._player_level > 50 && _player._player_level <= 60) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 96) {
            _weapon._weapon_material = __material.at(6);
        }
        else {
            _weapon._weapon_material = __material.at(5);
        }
    }
    else if (_player._player_level > 60 && _player._player_level <= 70) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 97) {
            _weapon._weapon_material = __material.at(7);
        }
        else {
            _weapon._weapon_material = __material.at(6);
        }
    }
    else if (_player._player_level > 70 && _player._player_level <= 80) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 98) {
            _weapon._weapon_material = __material.at(8);
        }
        else {
            _weapon._weapon_material = __material.at(7);
        }
    }
    else if (_player._player_level > 80 && _player._player_level <= 90) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 98) {
            _weapon._weapon_material = __material.at(9);
        }
        else {
            _weapon._weapon_material = __material.at(8);
        }
    }
    else if (_player._player_level > 90) {
        int rng = rand() % (100 - 0 + 1) + 0;
        if (rng > 99) {
            _weapon._weapon_material = __material.at(10);
        }
        else {
            _weapon._weapon_material = __material.at(9);
        }
    }

    if (_weapon._weapon_material == __material.at(0)) {
        //RANDOMISE ATTACK VARIABLES
    }
    else if (_weapon._weapon_material == __material.at(1)) {

    }
    else if (_weapon._weapon_material == __material.at(2)) {

    }
    else if (_weapon._weapon_material == __material.at(3)) {

    }
    else if (_weapon._weapon_material == __material.at(4)) {

    }
    else if (_weapon._weapon_material == __material.at(5)) {

    }
    else if (_weapon._weapon_material == __material.at(6)) {

    }
    else if (_weapon._weapon_material == __material.at(7)) {

    }
    else if (_weapon._weapon_material == __material.at(8)) {

    }
    else if (_weapon._weapon_material == __material.at(9)) {

    }
    else if (_weapon._weapon_material == __material.at(10)) {

    }

    return _weapon;
}

Player createPlayer() {
    Player _player;
    cout << "Whats your name: ";
    cin >> _player._player_name;
    _player._player_level = 1;
    _player._player_health = 100;
    _player._player_health_max = 100;
    _player._player_stamina = 100;
    _player._player_mana = 100;
    _player._player_mana_max = 100;
    _player._player_exp = 0;
    _player._player_exp_max = 100;
    _player._player_silver_coins = 0;
    _player._equipped_weapon = createWeaponRandom();

    std::vector<std::string> __special_attack =
    {
        "Crush", "Pierce", "Counter", "Parry", "Throw", "Neck lock", "Rip", "Slice", "Shatter", "Front flip kick", "Back flip kick"
    };
    _player._player_special_attack = __special_attack.at(rand() % ((__special_attack.size() - 1) - 0 + 1) + 0);
    return _player;
}

Player levelSystem(Player _player) {
    if (_player._player_exp > _player._player_exp_max) {
        _player._player_level += 1;
        _player._player_exp_max = _player._player_exp_max * 2;
        _player._player_health_max = _player._player_health_max + (_player._player_health_max / 5);
        _player._player_health = _player._player_health_max;
        _player._player_stamina = _player._player_stamina + (_player._player_stamina / 10);
        _player._player_mana = _player._player_mana + (_player._player_mana / 10);
    }
    return _player;
}



void Clear()
{
#if defined _WIN32
    system("cls");
#endif
}

