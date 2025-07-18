#include <iostream>

#include "raylib.h"


int main() {
    InitWindow(500, 1000, "Pong");
    SetTargetFPS(165);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("some text", 10, 10, 20, BLACK);
        DrawFPS(100, 100);
        EndDrawing();
    }

    CloseWindow();

    }
