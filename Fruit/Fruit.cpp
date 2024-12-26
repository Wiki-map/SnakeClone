//
// Created by wiki on 12/24/2024.
//
#include "Fruit.h"
#include "ctime"
#include "random"
#include "../GameGlobalObjects.h"

int Fruit::getX() {
    return x;
}

int Fruit::getY() {
    return y;
}

void Fruit::swichPos() {

    srand(time(nullptr));

    x = rand() % 30;
    y = rand() % 20;

}

void Fruit::Draw() {

    DrawMatrix[x][y] = RED;

}

Fruit::Fruit() {

    swichPos();

}

