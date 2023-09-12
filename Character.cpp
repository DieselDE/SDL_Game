#include <iostream>

using std::cout, std::endl;

class Character{
    public:

    int HP;
    int ATK;
    int DEF;

    Character create(Character* Player) {
        Player->HP = 100;
        Player->ATK = 30;
        Player->DEF = 20;

        return *Player;
    }
    Character lvl_up(Character* Player) {
        Player->HP += 5;
        Player->ATK += 3;
        Player->DEF += 2;

        return *Player;
    }
};

class Enemy{
    public:

    int HP;
    int ATK;
    int DEF;

    Enemy create_Goblin(Enemy* Goblin, int lvl) {
        Goblin->HP = 30 + (5 * lvl);
        Goblin->ATK = 10 + (3 * lvl);
        Goblin->DEF = 10 + (2 * lvl);

        return *Goblin;
    }
    Enemy create_Zombie(Enemy* Zombie, int lvl) {
        Zombie->HP = 40 + (5 * lvl);
        Zombie->ATK = 7 + (3 * lvl);
        Zombie->DEF = 20 + (2 * lvl);

        return *Zombie;
    }
};