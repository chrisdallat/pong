#include "../include/paddle.hpp"

Paddle::Paddle() 
{
    std::cout << "Initialising Paddle" << std::endl;
}

Paddle::~Paddle() 
{
    std::cout << "Destroying Paddle" << std::endl;
}

int Paddle::get_paddle_size()
{
	std::cout << "get_paddle_size()" << std::endl;
}

void Paddle::set_paddle_size()
{
	std::cout << "set_paddle_size" << std::endl;
}



