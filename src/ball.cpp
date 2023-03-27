#include "ball.hpp"

Ball::Ball() 
{
    std::cout << "Initialising Ball Object" << std::endl;
    m_xpos = GetScreenWidth() / 2;
    m_ypos = GetScreenHeight() / 2;
    m_xspeed = 5;
    m_yspeed = 5;
    m_radius = 5;
}

Ball::~Ball() 
{
    std::cout << "Destroying Ball" << std::endl;
}
void Ball::draw_ball()
{
    DrawCircle(get_xpos(), get_ypos(), get_radius(), WHITE);
}

void Ball::move_ball()
{
    draw_ball();
    // move ball withing confines of the window
    if(get_xpos() < GetScreenWidth() && get_xspeed() > 0)
        set_xpos(get_xspeed());
    else if(get_xpos() > 0 && get_xspeed() < 0)   
        set_xpos(get_xspeed());
    else
        reset_ball();
    

    if(get_ypos() < GetScreenHeight() && get_yspeed() > 0)
        set_ypos(get_yspeed());
    else if(get_ypos() > 0 && get_yspeed() < 0) 
        set_ypos(get_yspeed());
    else
        set_yspeed(get_yspeed() * -1);
}

void Ball::reset_ball()
{
    m_xpos = GetScreenWidth() / 2;
    m_ypos = GetScreenHeight() / 2;
    m_xspeed = 5;
    m_yspeed = 5;
}

float Ball::get_xpos()
{
    return m_xpos;
}

void Ball::set_xpos(int speed)
{
    m_xpos += speed;
}

float Ball::get_ypos()
{
    return m_ypos;
}

void Ball::set_ypos(int speed)
{
    m_ypos += speed;
}

int Ball::get_xspeed()
{
    return m_xspeed;
}

void Ball::set_xspeed(int speed)
{
    m_xspeed = speed;
}

int Ball::get_yspeed()
{
    return m_yspeed;
}

void Ball::set_yspeed(int speed)
{
    m_yspeed = speed;
}
        
int Ball::get_radius()
{
    return m_radius;
}

void Ball::set_radius(int radius)
{
	m_radius = radius;
}



