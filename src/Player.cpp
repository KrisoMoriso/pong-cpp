
#include "Player.h"
#include "raylib.h"
void Player::draw() {
    DrawRectangleV(m_pos, m_size, m_color);
    m_rectangle = Rectangle({m_pos.x, m_pos.y, m_size.x, m_size.y});
}

void Player::move() {
    m_pos.y += m_speed_y;
}

Player::Player(Vector2 pos, Vector2 size, Color color) {
    m_pos = pos;
    m_size = size;
    m_color = color;
    m_rectangle = Rectangle({pos.x, pos.y, size.x, size.y});
    m_speed_y = 0;
    m_score = 0;

}
