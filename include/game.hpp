#ifndef GAME_HPP
#define GAME_HPP

#include <string>
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
        void                keep_score();

    private:
        
        Ball                m_ball;
        Paddle              m_player1;
        Paddle              m_player2;

        bool                m_exit = false;
};

#endif

