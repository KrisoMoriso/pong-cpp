#pragma once
#include "raylib.h"


class Ball {
public:
    Vector2 m_pos; //upright corner
    Vector2 m_size;
    Vector2 m_speed;
    Color m_color;
    Vector2 m_center;
    float m_radius;
    bool m_did_init;
    void draw();
    void move();
    Ball(Vector2 pos, Vector2 size, Vector2 speed, Color color);
    Ball() {}
};




