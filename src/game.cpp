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
    keep_score();
}

void Game::collision_detect()
{
    // player 1 collision detection
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player1.getRect()))
        m_ball.set_xspeed(m_ball.get_xspeed() * -1);

    // player 2 collision detection
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player2.getRect()))
        m_ball.set_xspeed(m_ball.get_xspeed() * -1);  
}

void Game::keep_score()
{
    std::string score1 = std::to_string(m_ball.get_score1());
    std::string score2 = std::to_string(m_ball.get_score2());
    std::string score_string = score1 + " : " + score2;
    std::cout << score1 << std::endl;
    int offset = (GetScreenWidth() / 2) - (MeasureText(score_string.c_str(), 20) / 2);
    DrawText(score_string.c_str(), offset, 10, 20, WHITE);
}




