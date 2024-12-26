#include "raylib.h"
#include "GameGlobalObjects.h"


const int screenWidth = 900;
const int screenHeight = 600;

int main(){

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(12);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        if (!RESTART && !WIN) {

            snake.Draw();
            snake.Update();

            fruit.Draw();

            DrawMatrixColor();

            Collision();
        }
        else if (!WIN) {
            DrawText("GAME OVER", 200, 100, 100, BLACK);
        }

        if (WIN) {
            DrawText("YOU WON", 200, 100, 100, BLACK);
        }

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}