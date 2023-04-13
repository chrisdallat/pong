#ifndef BALL_HPP
#define BALL_HPP

#define DEFAULT_BALL_BOUNCE 5
#define DEFAULT_BALL_PEAK 15
#define DEFAULT_BALL_RADIUS 8
#define DEFAULT_BALL_XSPEED 4
#define DEFAULT_BALL_YSPEED 3
#define PADDING 50


#include <iostream>
#include "audio.hpp"
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
        void                ball_radius_maintain();
        
        int                 get_score1();
        void                point_player1();
        
        int                 get_score2();  
        void                point_player2();
               
        void                reset_score();
        void                set_score();
        void                serve_ball_position(float x, float y);

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

        Audio               m_audio;

        int                 m_player1_score;
        int                 m_player2_score;
        
        float               m_xpos;
        float               m_ypos;
        float               m_xspeed;
        float               m_yspeed;   
        float               m_radius;

        float               m_bounce_left = GetScreenWidth() / 3;
        float               m_bounce_right = (GetScreenWidth() / 3) * 2;
        float               m_bounce_ypos;

};

#endif
