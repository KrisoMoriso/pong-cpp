
#include "Ball.h"
void Ball::Draw() {
    Vector2 center;
    center.x = m_pos.x + m_size.x / 2;
    center.y = m_pos.y + m_size.y / 2;
    DrawCircleV(center, m_size.x / 2,  m_color);
}

Ball::Ball(Vector2 pos, Vector2 size, Vector2 speed,  Color color) {
    m_pos = pos;
    m_size = size;
    m_color = color;
    m_speed = speed;
}
