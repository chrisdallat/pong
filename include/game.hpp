#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"

#include "raylib.h"

class Game
{
    public:
        Game();
        ~Game();

        void                run_game();

        void                collision_detect();

    private:
        

        Ball                m_ball;
        Paddle              m_player1;
        Paddle              m_player2;

        int                 m_player1_score;
        int                 m_player2_score;

        bool                m_exit = false;
};

#endif

