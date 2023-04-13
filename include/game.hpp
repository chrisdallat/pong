#ifndef GAME_HPP
#define GAME_HPP

#define PLAYER_1    1
#define PLAYER_2    2
#define PLAYER_AI   3
#define EASY        6   
#define MEDIUM      4
#define HARD        2

#include <string>
#include <iostream>
#include <random>

#include "audio.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "powerup.hpp"

#include "raylib.h"

class Game
{
    public:
        Game();
        Game(std::string players, std::string powerups, std::string difficulty, std::string points);
        ~Game();

        int                 run_game();
        void                collision_powerup();
        void                collision_detect();

        void                powerup_effect();
        void                alter_trajectory(int player);
        void                change_speeds(float x, float y);
        void                keep_score();
        int                 game_over();

        void                serve();
        void                serve_direction(int player);
        void                ai_paddle();
        void                ai_serve();

        void                set_points_limit(int points);
        int                 get_points_limit();

        void                set_winner(int winner);
        int                 get_winner();     

    private:
        
        Ball                m_ball;
        Paddle              m_player1;
        Paddle              m_player2;
        Powerup             m_powerup;
        Audio               m_audio;

        bool                m_in_play = false;
        bool                m_exit = false;

        int                 m_game_points = 0;
        int                 m_last_serve = 2;

        bool                m_ai_player = true;
        bool                m_powerups = true;
        int                 m_current_powerup = 0;
        int                 m_difficulty = 1;
        int                 m_points_limit = 3;
        int                 m_winner = 0;
        
};

#endif

