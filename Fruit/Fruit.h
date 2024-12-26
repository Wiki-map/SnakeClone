//
// Created by wiki on 12/24/2024.
//
#ifndef GAME_FRUIT_H
#define GAME_FRUIT_H

#include "raylib.h"

class Fruit {
private:
    int x;
    int y;
public:
    Fruit();
    int getX();
    int getY();
    void swichPos();
    void Draw();
};

#endif //GAME_FRUIT_H
