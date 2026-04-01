#pragma once
#include "Player.h"
#include "Ball.h"


class Game {
public:
    int m_height;
    int m_width;
    double m_time;
    bool m_did_start;
    Ball m_ball;
    Player m_player1;
    Player m_player2;
    void init();
    void draw();
    void update();
    void menu();
};




