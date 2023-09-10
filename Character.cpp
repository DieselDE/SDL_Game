#include <iostream>

#include "Character.hpp"
#include "qmaths.hpp"

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
    Goblin->HP = 30 + enemylvld("HP", lvl);
    Goblin->ATK = 10 + enemylvld("ATK", lvl);
    Goblin->DEF = 10 + enemylvld("DEF", lvl);

    return *Goblin;
}

Enemy Enemy::create_Zombie(Enemy* Zombie, int lvl) {
    Zombie->HP = 40 + enemylvld("HP", lvl);
    Zombie->ATK = 7 + enemylvld("HP", lvl);
    Zombie->DEF = 20 + enemylvld("HP", lvl);

    return *Zombie;
}

int main(){
    Character Player;
    Player.create(&Player);
    Player.lvl_up(&Player);

    Enemy Goblin;
    Goblin.create_Goblin(&Goblin, 1);

    cout << Player.HP << endl;
    cout << Goblin.HP << endl;
}