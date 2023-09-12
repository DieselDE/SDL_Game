#include <iostream>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character{
    public:

    int HP;
    int ATK;
    int DEF;

    Character create(Character*);
    Character lvl_up(Character*);
};

class Enemy{
    public:

    int HP;
    int ATK;
    int DEF;

    Enemy create_Goblin(Enemy*, int);
    Enemy create_Zombie(Enemy*, int);
};

#endif