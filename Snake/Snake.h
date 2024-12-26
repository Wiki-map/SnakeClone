//
// Created by alecu on 12/24/2024.
//

#ifndef GAME_SNAKE_H
#define GAME_SNAKE_H

#include "raylib.h"
#include "vector"
#include "Direction.h"


class Snake {
private:

    Vector2 body[9000]{};
    int Size;
    Direction direction;

    int DrawSize;

public:

    bool ShodRestart = false;
    bool ShodWin = false;

    Snake(int StartPosX,int StartPosY);

    void Update();

    void Draw();

    void Grow();

    void IncreaseSize();

    Vector2 GetSnakeHead();

};


#endif //GAME_SNAKE_H
