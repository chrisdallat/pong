#include "paddle.hpp"

Paddle::Paddle()
{
    std::cout << "Default constructor: Paddle" << std::endl;
}

Paddle::Paddle(int player)
{
    std::cout << "Initialising Paddle" << std::endl;
    set_length(100);
    set_width(10);
    set_yspeed(5);
    m_ypos = GetScreenHeight()/2 - PADDING;

    if(player == 1)
        m_xpos = PADDING;
    if(player == 2)
        m_xpos = GetScreenWidth() - PADDING;

}

Paddle::~Paddle() 
{
    std::cout << "Destroying Paddle" << std::endl;
}

void Paddle::draw_paddle()
{
    DrawRectanglePro(getRect(),Vector2{5,50}, m_rotation, WHITE);
}

void Paddle::move_paddle(int player)
{   
    draw_paddle();
    set_rotation(35.0);
    
    if(player == 1)
    {
        if(IsKeyDown(KEY_W) && within_upper())
            set_ypos(get_yspeed() * -1);
        else if(IsKeyDown(KEY_S) && within_lower())
            set_ypos(get_yspeed());  
    }
    if(player == 2)
    {
        if(IsKeyDown(KEY_UP) && within_upper())
            set_ypos(get_yspeed() * -1);
        else if(IsKeyDown(KEY_DOWN) && within_lower())
            set_ypos(get_yspeed());  
    }
}

bool Paddle::within_upper()
{
    // is paddle within upper boundary
    if((get_ypos()) >= 0)
        return true;
    
    return false;
}

bool Paddle::within_lower()
{
    // is paddle within upper boundary
    if((get_ypos() + get_length()) < GetScreenHeight())
        return true;
    
    return false;
}

float Paddle::get_length()
{
	return m_length;
}

void Paddle::set_length(int length)
{
	m_length = length;
}

float Paddle::get_width()
{
	return m_width;
}

void Paddle::set_width(int width)
{
	m_width = width;
}

float Paddle::get_xpos()
{
    return m_xpos;
}

void Paddle::set_xpos(int speed)
{
	m_xpos += speed;
}

float Paddle::get_ypos()
{
    return m_ypos;
}

void Paddle::set_ypos(int speed)
{
	m_ypos += speed;
}

float Paddle::get_rotation()
{
    return m_rotation;
}

void Paddle::set_rotation(float degrees)
{
    m_rotation = degrees;
}

int Paddle::get_xspeed()
{
    return m_xspeed;
}

void Paddle::set_xspeed(int speed)
{
	m_xspeed = speed;
}

int Paddle::get_yspeed()
{
    return m_yspeed;
}

void Paddle::set_yspeed(int speed)
{
	m_yspeed = speed;
}

Rectangle Paddle::getRect()
{
    return Rectangle{get_xpos(), get_ypos(), get_width(), get_length()};
}

