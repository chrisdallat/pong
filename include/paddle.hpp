#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>
#include "raylib.h"

class Paddle 
{
    public:
        Paddle();
        Paddle(int player);
        ~Paddle();

        void                draw_paddle();
        void                move_paddle(int player);

        bool                within_upper();
        bool                within_lower();

        int                 get_length();
        void                set_length(int length);

        int                 get_width();
        void                set_width(int width);

        int                 get_xpos();
        void                set_xpos(int speed);

        int                 get_ypos();
        void                set_ypos(int speed);

        int                 get_xspeed();
        void                set_xspeed(int speed); 
        
        int                 get_yspeed();
        void                set_yspeed(int speed);

    private:
        
        //other private class variables
        int                 m_length;
        int                 m_width;
        int                 m_xpos;
        int                 m_ypos;
        int                 m_xspeed;
        int                 m_yspeed;      


};

#endif
