#include <iostream>

#include "Character.hpp"

using namespace std;

Character Character::create(Character* Player) {
    Player->HP = 100;
    Player->ATK = 30;
    Player->DEF = 20;

    return *Player;
}

Character Character::lvl_up(Character* Player) {
    Player->HP += 5;
    Player->ATK += 3;
    Player->DEF += 2;

    return *Player;
}

Enemy Enemy::create_Goblin(Enemy* Goblin, int lvl) {
    Goblin->HP = 30 + (5 * lvl);
    Goblin->ATK = 10 + (3 * lvl);
    Goblin->DEF = 10 + (2 * lvl);

    return *Goblin;
}

Enemy Enemy::create_Zombie(Enemy* Zombie, int lvl) {
    Zombie->HP = 40 + (5 * lvl);
    Zombie->ATK = 7 + (1 * lvl);
    Zombie->DEF = 20 + (4 * lvl);

    return *Zombie;
}