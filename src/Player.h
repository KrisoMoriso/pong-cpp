#pragma once
#include "raylib.h"


class Player {
public:
    Vector2 m_pos{};
    Vector2 m_size{};
    Color m_color{};
    void draw();
    Player(Vector2 pos, Vector2 size, Color color);
    Player() {
    }
};



