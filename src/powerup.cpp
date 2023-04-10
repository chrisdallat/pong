#include "powerup.hpp"

Powerup::Powerup()
{
    std::cout << "----Generating Powerup------" << std::endl;
    generate_new_powerup();
}

Powerup::~Powerup()
{

}

void Powerup::generate_new_powerup()
{
    generate_xpos();
    generate_ypos();
    set_powerup_radius(POWERUP_MEDIUM);
}

void Powerup::draw_powerup_drop()
{
    DrawCircle(get_powerup_xpos(), get_powerup_ypos(), get_powerup_radius(), ORANGE);
    DrawCircle(get_powerup_xpos(), get_powerup_ypos(), get_powerup_radius() - 2, BLACK);
}

void Powerup::generate_xpos()
{
    float pos = rand() % (GetScreenWidth() - 200) + POWERUP_LARGE;
    set_powerup_xpos(pos); 
    std::cout << "Powerup x_pos: " << get_powerup_xpos() << std::endl;
}

void Powerup::generate_ypos()
{
    float pos = rand() % GetScreenHeight();
    set_powerup_ypos(pos); 
    std::cout << "Powerup y_pos: " << get_powerup_ypos() << std::endl;
}

float Powerup::get_powerup_xpos()
{
    return m_powerup_xpos;
}

void Powerup::set_powerup_xpos(float x_pos)
{
    m_powerup_xpos = x_pos;
}

float Powerup::get_powerup_ypos()
{
    return m_powerup_ypos;
}

void Powerup::set_powerup_ypos(float y_pos)
{
    m_powerup_ypos = y_pos;
}

int Powerup::get_powerup_radius()
{
    return m_powerup_radius;
}

void Powerup::set_powerup_radius(int radius)
{
    m_powerup_radius = radius;
}

