#include "Game.h"
#include "Ball.h"
#include "Player.h"
#define PLAYER_SPEED 2

void Game::init() {
    m_width = 1000;
    m_height = 600;
    InitWindow(m_width, m_height, "Pong");
    SetTargetFPS(165);
    SetExitKey(KEY_NULL);
    m_ball = Ball({(float)m_width / 2, (float)m_height / 2}, {10, 10}, {0, 0}, BLUE);
    m_player1 = Player({50,  (float)m_height / 2}, {25, 100}, GRAY);
    m_player2 = Player({(float)m_width - 50,  (float)m_height / 2}, {25, 100}, GRAY);
}
void Game::menu() {
    m_did_start = true;
}


void Game::draw() {
    BeginDrawing();
    ClearBackground(WHITE);
    m_ball.draw();
    m_player1.draw();
    m_player2.draw();
    DrawText(TextFormat("%d", m_player2.m_score), 150, 50, 50, BLACK);
    DrawText(TextFormat("%d", m_player1.m_score), m_width - 150, 50, 50, BLACK);
    EndDrawing();
}

void Game::update() {
    //update ball
    m_ball.move();
    //update players
    m_player1.move();
    m_player2.move();
    //start ball
    if ((IsKeyDown(KEY_S) or IsKeyDown(KEY_W) or IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_UP)) and !m_ball.m_did_init) {
        bool x = GetRandomValue(0 , 1);
        float y;
        if (x) {y = 1;} else {y = -1;}
        m_ball.m_speed = Vector2({float(GetRandomValue(800, 1500))/1000*y, float(GetRandomValue(800 , 1500))/1000*y});
        m_ball.m_did_init = true;
    }
    //turn on for playing vs ai
    m_player2.m_speed_y = m_ball.m_speed.y*0.8;
    if (IsKeyDown(KEY_S)) {m_player1.m_speed_y = PLAYER_SPEED;}
    if (IsKeyDown(KEY_W)) {m_player1.m_speed_y = -PLAYER_SPEED;}
    if (!(IsKeyDown(KEY_S) or IsKeyDown(KEY_W))) {m_player1.m_speed_y = 0;}
    //-----------turn off for ai gameplay-----------------------------------------------
    // if (IsKeyDown(KEY_DOWN)) {m_player2.m_speed_y = PLAYER_SPEED;}
    // if (IsKeyDown(KEY_UP)) {m_player2.m_speed_y = -PLAYER_SPEED;}
    // if (!(IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_UP) )) {m_player2.m_speed_y = 0;}
    //---------------------------------------------------------------------------------
    //player1 vs wall
    if (m_player1.m_pos.y + m_player1.m_size.y >= m_height) {
        m_player1.m_pos.y = m_height - m_player1.m_size.y;
    }
    if (m_player1.m_pos.y <= 0) {
        m_player1.m_pos.y = 0;
    }
    //player2 vs wall
    if (m_player2.m_pos.y + m_player2.m_size.y >= m_height) {
        m_player2.m_pos.y = m_height - m_player2.m_size.y;
    }
    if (m_player2.m_pos.y <= 0) {
        m_player2.m_pos.y = 0;
    }



    //ball vs horizontal
    if (m_ball.m_pos.y <= 0 or m_ball.m_pos.y + m_ball.m_size.y >= m_height) {
        m_ball.m_speed.y *= -1;
    }
    //ball vs vertical
    if (m_ball.m_pos.x <= 0) {
        m_player1.m_score += 1;
        m_ball.m_pos = Vector2{(float)m_width / 2, (float)m_height / 2};
        m_ball.m_speed = Vector2{0,0};
        m_ball.m_did_init = false;
    }
    if (m_ball.m_pos.x >= m_width) {
        m_player2.m_score += 1;
        m_ball.m_pos = Vector2{(float)m_width / 2, (float)m_height / 2};
        m_ball.m_speed = Vector2{0,0};
        m_ball.m_did_init = false;
    }
    //ball vs player 1
    if (CheckCollisionCircleRec(m_ball.m_center, m_ball.m_radius, m_player1.m_rectangle)
        and m_ball.m_center.x >= m_player1.m_pos.x + m_player1.m_size.x) {
        m_ball.m_speed.x *= -1;
        m_ball.m_speed.x += 0.1;
        m_ball.m_pos.x = m_player1.m_pos.x + m_player1.m_size.x + 1;
        float x = m_ball.m_pos.y - m_player1.m_pos.y;
        x /= m_player1.m_size.y;
        if (x < 0.3) {
            m_ball.m_speed.y = -8 * x;
        } else if (x > 0.7) {
            m_ball.m_speed.y = 8 * (x-0.7);
        }
    }
    //ball vs player 2
    if (CheckCollisionCircleRec(m_ball.m_center, m_ball.m_radius, m_player2.m_rectangle)
        and m_ball.m_center.x <= m_player2.m_pos.x) {
        m_ball.m_speed.x *= -1;
        m_ball.m_speed.x += -0.1;
        m_ball.m_pos.x = m_player2.m_pos.x - 1 - m_ball.m_size.x;
        float x = m_ball.m_pos.y - m_player2.m_pos.y;
        x /= m_player2.m_size.y;
        if (x < 0.3) {
            m_ball.m_speed.y = -6 * x;
        } else if (x > 0.7) {
            m_ball.m_speed.y = 6 * (x-0.5);
        }
        }




}


