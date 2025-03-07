#include "header.h"



    Piece(int life, int damage, char character) : life(life), damage(damage), character(character) {}
    virtual ~Piece() {}
    //getters.
    int getLife() const { return life; }
    int getDamage() const { return damage; }
    char getCharacter() const { return character; }

    virtual void performAttack() = 0;//abstract function
    virtual void reduceLife(int amount) { life -= amount; }
};