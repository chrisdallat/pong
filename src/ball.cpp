#include "ball.hpp"

Ball::Ball() 
{
    std::cout << "Initialising Ball Object" << std::endl;
    m_xpos = GetScreenWidth() - 51;
    m_ypos = GetScreenHeight() / 2;
    set_xspeed(-(DEFAULT_BALL_SPEED));
    set_yspeed(DEFAULT_BALL_SPEED);
    set_radius(DEFAULT_BALL_RADIUS);
    reset_score();
}

Ball::~Ball() 
{
    std::cout << "Destroying Ball" << std::endl;

}
void Ball::draw_ball()
{
    DrawCircle(get_xpos(), get_ypos(), get_radius(), WHITE);
}

void Ball::draw_bounce()
{
    std::cout << "TODO: make bounce feeback > ball.cpp[26]" << std::endl;
    DrawCircle(get_xpos(), get_ypos(), get_radius(), WHITE);
}

void Ball::bounce()
{
    int bounce_left = GetScreenWidth() / 3;
    int bounce_right = bounce_left * 2;
    float small_inc = (get_xspeed() * DEFAULT_BALL_INC) / bounce_left; //increment for small side
    float large_inc = (get_xspeed() * DEFAULT_BALL_INC) / bounce_right;//increment for large side
    float new_radius;

    if((get_xpos() < bounce_left))
        draw_bounce();

    // right to left ball flight
    if(get_xspeed() < 0 && get_xpos() > bounce_left)
    {
        new_radius = get_radius() + large_inc;
        set_radius(new_radius);
    }
    if(get_xspeed() < 0 && get_xpos() < bounce_left)
    {
        new_radius = get_radius() - small_inc;
        set_radius(new_radius);
    }
    // left to right ball flight
    else if(get_xspeed() > 0 && get_xpos() > bounce_right)
    {
        new_radius = get_radius() + small_inc;
        set_radius(new_radius);
    }   
    else if(get_xspeed() > 0 && get_xpos() < bounce_right)
    {
        new_radius = get_radius() - large_inc;
        set_radius(new_radius);
    }
}

void Ball::move_ball()
{
    draw_ball();
    bounce();
    // move ball withing confines of the window
    if(get_xpos() < GetScreenWidth() && get_xspeed() > 0)
        set_xpos(get_xspeed());
    else if(get_xpos() > 0 && get_xspeed() < 0)   
        set_xpos(get_xspeed());
    else
    {
        set_score();
        reset_ball();
    }

    if(get_ypos() < GetScreenHeight() && get_yspeed() > 0)
        set_ypos(get_yspeed());
    else if(get_ypos() > 0 && get_yspeed() < 0) 
        set_ypos(get_yspeed());
    else
        set_yspeed(get_yspeed() * -1);
}

int Ball::get_score1()
{
    return m_player1_score;
}

void Ball::point_player1()
{
    m_player1_score += 1;
}
        
int Ball::get_score2()
{
    return m_player2_score;
}  

void Ball::point_player2()
{
    m_player2_score += 1;
}

void Ball::reset_score()
{
    m_player1_score = 0;
    m_player2_score = 0;
}

void Ball::set_score()
{
    if(get_xspeed() > 0)
        point_player1();
    if(get_xspeed() < 0)
        point_player2();
}

void Ball::reset_ball()
{
    m_xpos = GetScreenWidth() - 50;
    m_ypos = GetScreenHeight() / 2;
    // if (m_xspeed > 0)
        m_xspeed = -5;
    // else
    //     m_xspeed = 5;
}

float Ball::get_xpos()
{
    return m_xpos;
}

void Ball::set_xpos(float speed)
{
    m_xpos += speed;
}

float Ball::get_ypos()
{
    return m_ypos;
}

void Ball::set_ypos(float speed)
{
    m_ypos += speed;
}

float Ball::get_xspeed()
{
    return m_xspeed;
}

void Ball::set_xspeed(float speed)
{
    m_xspeed = speed;
}

float Ball::get_yspeed()
{
    return m_yspeed;
}

void Ball::set_yspeed(float speed)
{
    m_yspeed = speed;
}
        
float Ball::get_radius()
{
    return m_radius;
}

void Ball::set_radius(float radius)
{
	m_radius = radius;
}



