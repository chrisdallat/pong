#include "ball.hpp"

Ball::Ball() 
{
    std::cout << "Initialising Ball Object" << std::endl;
    m_xpos = GetScreenWidth() - 51;
    m_ypos = GetScreenHeight() / 2;
    m_bounce_ypos = -1;
    set_xspeed(-(DEFAULT_BALL_XSPEED));
    set_yspeed(DEFAULT_BALL_YSPEED);
    set_radius(DEFAULT_BALL_RADIUS);
    reset_score();
}

Ball::~Ball() 
{
    std::cout << "Destroying Ball" << std::endl;

}
void Ball::draw_ball()
{
    DrawCircleGradient(get_xpos(), get_ypos(), get_radius(), WHITE, DARKGRAY);
}

void Ball::draw_bounce()
{
    // if ball is going correct direction and within bounce zone.
    if(((get_xspeed() < 0) && (get_xpos() > m_bounce_left - 40) && (get_xpos() < m_bounce_left)))
    {
        if(m_bounce_ypos >= 0)
        {

            DrawCircle(m_bounce_left, m_bounce_ypos, get_radius() + 5, GRAY);
            DrawCircle(m_bounce_left, m_bounce_ypos, get_radius() + 3, BLACK);
            DrawCircleGradient(get_xpos(), get_ypos(), get_radius(), WHITE, DARKGRAY);//game ball
            return;
        }
        else
        {
            m_bounce_ypos = get_ypos();
            return;
        }
    }
    if((get_xspeed() > 0) && (get_xpos() > m_bounce_right) && (get_xpos() < m_bounce_right + 40))
    {
        if(m_bounce_ypos >= 0)
        {
            DrawCircle(m_bounce_right, m_bounce_ypos, get_radius() + 5, GRAY);
            DrawCircle(m_bounce_right, m_bounce_ypos, get_radius() + 3, BLACK);
            DrawCircle(get_xpos(), get_ypos(), get_radius(), WHITE);//game ball
            return;
        }
        else
        {
            m_bounce_ypos = get_ypos();
            return;
        }
    }
    else
    {
        m_bounce_ypos = -1;
    }

}

void Ball::bounce()
{
    float bounce_to_hit_inc = (get_xspeed() * (DEFAULT_BALL_RADIUS - DEFAULT_BALL_BOUNCE) / (m_bounce_left - 50)); //increment for small side
    float peak_to_bounce_inc = ((get_xspeed() * (DEFAULT_BALL_PEAK - DEFAULT_BALL_BOUNCE)) / m_bounce_left);//increment for large side
    float hit_to_peak_inc = ((get_xspeed() * (DEFAULT_BALL_PEAK - DEFAULT_BALL_RADIUS)) / (m_bounce_left - 50));
    float new_radius;

    draw_bounce();

    // right to left ball flight
    if(get_xspeed() < 0 && get_xpos() > m_bounce_right)
    {
        new_radius = get_radius() - hit_to_peak_inc;
        set_radius(new_radius);
    }
    else if(get_xspeed() < 0 && get_xpos() < m_bounce_right && get_xpos() > m_bounce_left)
    {
        new_radius = get_radius() + peak_to_bounce_inc;
        set_radius(new_radius);
    }
    else if(get_xspeed() < 0 && get_xpos() < m_bounce_left)
    {
        new_radius = get_radius() - bounce_to_hit_inc;
        set_radius(new_radius);
    }
    // left to right ball flight
    else if(get_xspeed() > 0 && get_xpos() < m_bounce_left)
    {
        new_radius = get_radius() + hit_to_peak_inc;
        set_radius(new_radius);
    }   
    else if(get_xspeed() > 0 && get_xpos() < m_bounce_right)
    {
        new_radius = get_radius() - peak_to_bounce_inc;
        set_radius(new_radius);
    }
    else if(get_xspeed() > 0 && get_xpos() > m_bounce_right)
    {
        new_radius = get_radius() + bounce_to_hit_inc;
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

void Ball::serve_ball_position(float x, float y)
{
    m_xspeed = 0;
    m_yspeed = 0;
    set_radius(DEFAULT_BALL_RADIUS);
    m_xpos = x;
    m_ypos = y;
}

void Ball::set_score()
{
    if(get_xspeed() > 0)
        point_player1();
    if(get_xspeed() < 0)
        point_player2();
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



