#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include "raylib.h"

class Ball
{
    public:
        Ball();
        ~Ball();

        //testing: remove later
        void                draw_ball();
        void                move_ball();
        
        int                 get_score1();
        void                point_player1();
        
        int                 get_score2();  
        void                point_player2();
               
        void                reset_score();
        void                set_score();
        void                reset_ball();

        float               get_xpos();
        void                set_xpos(int speed);

        float               get_ypos();
        void                set_ypos(int speed);

        int                 get_xspeed();
        void                set_xspeed(int speed);

        int                 get_yspeed();
        void                set_yspeed(int speed);
        
        int                 get_radius();
        void                set_radius(int radius);

    private:

        int                 m_player1_score;
        int                 m_player2_score;
        
        float               m_xpos;
        float               m_ypos;
        int                 m_xspeed;
        int                 m_yspeed;   
        int                 m_radius;

};

#endif
