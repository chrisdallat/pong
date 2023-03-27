#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"

class Game
{
    public:
        Game();
        ~Game();

        //testing: remove later
        void                run_game();
    private:
        

        Ball                m_ball;
        Paddle              m_player1;
        Paddle              m_player2;

        int                 m_player1_score;
        int                 m_player2_score;

        bool                m_exit = false;
};

#endif

