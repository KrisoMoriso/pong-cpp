
#include "Player.h"
#include "raylib.h"
void Player::draw() {
    DrawRectangleV(m_pos, m_size, m_color);
}

Player::Player(Vector2 pos, Vector2 size, Color color) {
    m_pos = pos;
    m_size = size;
    m_color = color;
}
