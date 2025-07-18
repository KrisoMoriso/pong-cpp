#pragma once
#include "raylib.h"


class Ball {
public:
    Vector2 m_pos;
    Vector2 m_size;
    Vector2 m_speed;
    Color m_color;
    void Draw();
    Ball(Vector2 pos, Vector2 size, Vector2 speed, Color color);
    Ball() {}
};




