#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"

Game::Game() 
{
    std::cout << "Initialising Game Object" << std::endl;
    m_player1 = Paddle(1);
    m_player2 = Paddle(2);
}

Game::~Game() 
{
    std::cout << "Closing Game: Deconstructor" << std::endl;
}

void Game::run_game()
{   
    m_ball.move_ball();

    m_player1.move_paddle(1);
    m_player2.move_paddle(2);

    collision_detect();


}

void Game::collision_detect()
{
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player1.getRect()))
    {
        m_ball.set_xspeed(m_ball.get_xspeed() * -1);
    }
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player2.getRect()))
    {
        m_ball.set_xspeed(m_ball.get_xspeed() * -1);
    }     
}



