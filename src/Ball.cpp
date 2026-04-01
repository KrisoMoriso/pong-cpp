
#include "Ball.h"
void Ball::draw() {
    m_center.x = m_pos.x + m_size.x / 2;
    m_center.y = m_pos.y + m_size.y / 2;
    DrawCircleV(m_center, m_size.x / 2,  m_color);
}
void Ball::move() {
    m_pos.x += m_speed.x;
    m_pos.y += m_speed.y;
}


Ball::Ball(Vector2 pos, Vector2 size, Vector2 speed,  Color color) {
    m_pos = pos;
    m_size = size;
    m_color = color;
    m_speed = speed;
    m_did_init = false;
    m_center.x = m_pos.x + m_size.x / 2;
    m_center.y = m_pos.y + m_size.y / 2;
    m_radius = m_size.x / 2;
}
