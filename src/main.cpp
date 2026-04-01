#include <iostream>

#include "raylib.h"
#include "Game.h"

int main() {
    Game game;
    game.init();
    while (!WindowShouldClose()) {
        if (game.m_did_start) {
            game.draw();
            game.update();
        } else {
            game.menu();
        }
    }

    CloseWindow();

    }
