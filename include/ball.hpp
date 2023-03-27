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
        
        float                 m_xpos;
        float                 m_ypos;
        int                 m_xspeed;
        int                 m_yspeed;   
        int                 m_radius;

};

#endif
