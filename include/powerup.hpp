#ifndef POWERUP_HPP
#define POWERUP_HPP 

#define POWERUP_SMALL  40
#define POWERUP_MEDIUM 50
#define POWERUP_LARGE  60

#include <iostream>
#include <random>
#include <cmath>
#include <vector>

#include "raylib.h"

class Powerup
{
    public:

        Powerup();
        ~Powerup();

        void    generate_new_powerup();

        void    draw_powerup_drop();

        void    generate_xpos();
        void    generate_ypos();

        int     get_powerup_type();
        void    generate_powerup_type();

        float   get_powerup_xpos();
        void    set_powerup_xpos(float x_pos);

        float   get_powerup_ypos();
        void    set_powerup_ypos(float y_pos);

        int     get_powerup_radius();
        void    set_powerup_radius(int radius);

    private:
        
        float   m_powerup_xpos;
        float   m_powerup_ypos;
        int     m_powerup_radius;
        int     m_powerup_type;

};

#endif
