#pragma once
#include "raylib.h"


class Player {
public:
    Vector2 m_pos{};
    Vector2 m_size{};
    float m_speed_y;
    Color m_color{};
    int m_score;
    Rectangle m_rectangle;
    void draw();
    void move();
    Player(Vector2 pos, Vector2 size, Color color);
    Player() {
    }
};



