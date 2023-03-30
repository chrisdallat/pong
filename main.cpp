#include "include/window.hpp"
#include "include/paddle.hpp"
#include "include/ball.hpp"
#include "raylib.h"

#include "unistd.h"
#include "chrono"
#include "thread"

int main(int ac, char *av[])
{
	std::cout << "Welcome to Pong!" << std::endl;

	std::vector<std::string> args(av, av+ac);

  	for (size_t i = 1; i < args.size(); i++) {
      	if (args[i] == "game")
			Window w;
		}
	return 0;
}
