//
// Created by wiki on 12/24/2024.
//
#ifndef GAME_GAMEGLOBALOBJECTS_H
#define GAME_GAMEGLOBALOBJECTS_H

#include "Snake/Snake.h"
#include "Fruit/Fruit.h"

inline bool RESTART = false;
inline bool WIN = false;

inline Color DrawMatrix[30][20];

inline void DrawMatrixColor() {

    for (int i=0; i<900; i+=30) {
        DrawLine(i, 0, i, 600, GRAY);
    }

    for (int i=0; i<600; i+=30) {
        DrawLine(0, i, 900, i, GRAY);
    }

    for (int i=0; i<30; i++) {

        for (int j=0; j<20; j++) {

            DrawRectangle(i*30,j*30,30,30,DrawMatrix[i][j]);

            DrawMatrix[i][j] = {0,0,0,0};

        }

    }

}

inline Snake snake = Snake(15,10);

inline Fruit fruit = Fruit();

inline void Collision() {

    if (snake.GetSnakeHead().x == fruit.getX() && snake.GetSnakeHead().y == fruit.getY()) {
        fruit.swichPos();

        snake.Grow();
    }

}

#endif //GAME_GAMEGLOBALOBJECTS_H
