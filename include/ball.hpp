#ifndef BALL_HPP
#define BALL_HPP

#define DEFAULT_BALL_RADIUS 15
#define DEFAULT_BALL_SPEED 3
#define DEFAULT_BALL_INC 10

#include <iostream>

#include "raylib.h"

class Ball
{
    public:
        Ball();
        ~Ball();

        void                draw_ball();
        void                draw_bounce();
        void                bounce();
        void                move_ball();
        
        int                 get_score1();
        void                point_player1();
        
        int                 get_score2();  
        void                point_player2();
               
        void                reset_score();
        void                set_score();
        void                reset_ball();

        float               get_xpos();
        void                set_xpos(float speed);

        float               get_ypos();
        void                set_ypos(float speed);

        float               get_xspeed();
        void                set_xspeed(float speed);

        float               get_yspeed();
        void                set_yspeed(float speed);
        
        float               get_radius();
        void                set_radius(float radius);

    private:

        int                 m_player1_score;
        int                 m_player2_score;
        
        float               m_xpos;
        float               m_ypos;
        float               m_xspeed;
        float               m_yspeed;   
        float               m_radius;

};

#endif
