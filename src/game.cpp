#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "raylib.h"

Game::Game() 
{
    std::cout << "Initialising Game Object" << std::endl;
}

Game::~Game() 
{
    std::cout << "Closing Game: Deconstructor" << std::endl;
}

void Game::run_game()
{   
    m_ball.move_ball();
}



