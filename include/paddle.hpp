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

        float               get_length();
        void                set_length(int length);

        float               get_width();
        void                set_width(int width);

        float               get_xpos();
        void                set_xpos(int speed);

        float               get_ypos();
        void                set_ypos(int speed);

        int                 get_xspeed();
        void                set_xspeed(int speed); 
        
        int                 get_yspeed();
        void                set_yspeed(int speed);

        Rectangle           getRect();

    private:
        
        //other private class variables
        float                 m_length;
        float                 m_width;
        float                 m_xpos;
        float                 m_ypos;
        int                 m_xspeed;
        int                 m_yspeed;      


};

#endif
