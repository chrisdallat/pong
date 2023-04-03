#ifndef PADDLE_HPP
#define PADDLE_HPP

#define PADDING 50
#define DEFAULT_PADDLE_SPEED 5
#define DEFAULT_PADDLE_LENGTH 100
#define DEFAULT_PADDLE_WIDTH 10
#define HOLD_SPEED 1.4

#include <iostream>
#include <cmath>
#include <vector>

#include "raylib.h"

class Paddle 
{
    public:
        Paddle();
        Paddle(int player);
        ~Paddle();

        void                draw_paddle();
        void                move_paddle(int player);
        void                change_speed(int key);
        void                time_key(int key);

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

        int                 get_last_key();

        Rectangle           getRect();

    private:
        
        float                   m_length;
        float                   m_width;
        float                   m_xpos;
        float                   m_ypos;
        int                     m_xspeed;
        int                     m_yspeed;
        int                     m_last_key;
        bool                    m_key_pressed;
        int                     m_timer;

};

#endif
