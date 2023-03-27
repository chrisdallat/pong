#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "raylib.h"

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
    // m_player1.assign_side(1);
    // m_player2.assign_side(2);
    m_player1.move_paddle(1);
    m_player2.move_paddle(2);
}



