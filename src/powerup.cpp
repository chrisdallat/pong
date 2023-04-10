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
    generate_powerup_type();
    set_powerup_radius(POWERUP_MEDIUM);
}

void Powerup::draw_powerup_drop()
{
    DrawCircle(get_powerup_xpos(), get_powerup_ypos(), get_powerup_radius(), ORANGE);
    DrawCircle(get_powerup_xpos(), get_powerup_ypos(), get_powerup_radius() - 2, BLACK);
}

void Powerup::generate_xpos()
{
    float pos = rand() % (GetScreenWidth() - 200) + (get_powerup_radius() + 50);
    set_powerup_xpos(pos); 
}

void Powerup::generate_ypos()
{
    float pos = rand() % GetScreenHeight();
    set_powerup_ypos(pos); 
}

int Powerup::get_powerup_type()
{
    return m_powerup_type;
}

void Powerup::generate_powerup_type()
{
    // no power         0
    // invisiball       1
    // double/triple    2
    // reversiball      3
    // re-serve         4
    // mini-paddle      5
    // big-paddle       6
    m_powerup_type = 1;
    // m_powerup_type = rand() % 6 + 1;
    std::cout << "----powerup type --> " << m_powerup_type << std::endl;
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

