//
// Created by wiki on 12/24/2024.
//
#include "Snake.h"
#include "raylib.h"
#include "../GameGlobalObjects.h"

Snake::Snake(int StartPosX,int StartPosY) {

    body[0] = Vector2 (float(StartPosX),float(StartPosY));

    Size = 1;

    direction = EAST;

    DrawSize = Size;

}

void Snake::Draw() {

    for (int i=0; i < Size; i++) {

        if (i < Size / 5) {

            DrawMatrix[int(body[i].x)][int(body[i].y)] = {75,75,75, 255};

        }
        else if (i < Size / 2) {
            DrawMatrix[int(body[i].x)][int(body[i].y)] = {50,50,50, 255};
        }

        else if (i < Size / 2 + Size / 4) {
            DrawMatrix[int(body[i].x)][int(body[i].y)] = {30,30,30, 255};
        }

        else {
            DrawMatrix[int(body[i].x)][int(body[i].y)] = BLACK;
        }

    }

}

void Snake::Update() {

    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && direction != SOUTH) {
        direction = NORTH;
    }
    else if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && direction != WEST) {
        direction = EAST;
    }
    else if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && direction != NORTH) {
        direction = SOUTH;
    }
    else if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && direction != EAST) {
        direction = WEST;
    }

    for (int i=Size - 1; i>-1; i--) {

        if (i == 0) {

            if (direction == NORTH) {
                body[i].y -= 1;
            }
            else if (direction == EAST) {
                body[i].x += 1;
            }
            else if (direction == SOUTH) {
                body[i].y += 1;
            }
            else if (direction == WEST) {
                body[i].x -= 1;
            }

        }
        else body[i] = body[i-1];

    }

    for (int i=0; i<Size; i++) {
        for (int j=0; j<Size; j++) {
            if (body[i].x == body[j].x && body[i].y == body[j].y && i != j) {
                RESTART = true;
            }
        }
    }

    if (Size == 600) WIN = true;

    if (body[0].x >= 30 || body[0].x < 0 || body[0].y >= 20 || body[0].y < 0) RESTART = true;

    DrawSize = Size;

}

void Snake::Grow() {
    body[Size] = body[Size-1];

    Size++;
}

Vector2 Snake::GetSnakeHead() {

    return body[0];

}
