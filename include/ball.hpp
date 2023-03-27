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

        int                 get_xpos();
        void                set_xpos(int speed);

        int                 get_ypos();
        void                set_ypos(int speed);

        int                 get_xspeed();
        void                set_xspeed(int speed);

        int                 get_yspeed();
        void                set_yspeed(int speed);
        
        int                 get_ball_size();
        void                set_ball_size(int ball_size);

    private:
        
        int                 m_xpos;
        int                 m_ypos;
        int                 m_xspeed;
        int                 m_yspeed;   
        int                 m_ball_size;

};

#endif
