#include "include/window.hpp"
#include "include/paddle.hpp"
#include "include/ball.hpp"
#include "raylib.h"

#include "unistd.h"
#include "chrono"
#include "thread"

int main(int ac, char *av[])
{
	std::vector<std::string> args(av, av+ac);

	std::cout << "args: " << args[1] << args[2] << args[3] << args[4] << std::endl;
	Window w = Window(args[1], args[2], args[3], args[4]);

	return 0;
}
