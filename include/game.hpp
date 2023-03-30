#ifndef GAME_HPP
#define GAME_HPP

#define PLAYER_1 1
#define PLAYER_2 2

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
        void                alter_trajectory(int player);
        void                change_speeds(float x, float y);
        void                keep_score();
        void                serve();
        void                serve_direction(int player);

    private:
        
        Ball                m_ball;
        Paddle              m_player1;
        Paddle              m_player2;

        bool                m_in_play = false;
        bool                m_exit = false;
        int                 m_game_points;
        int                 m_last_serve = 1;
        
};

#endif

