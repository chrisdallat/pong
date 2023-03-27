#include "window.hpp"
#include "game.hpp"
#include "raylib.h"

Window::Window() 
{
    std::cout << "Initialising Window Object" << std::endl;

    InitWindow(1000, 600, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game;

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
            DrawFPS(10,10);
            game.run_game();
		EndDrawing();
	}
}

Window::~Window() 
{
    std::cout << "Closing Window: Deconstructor" << std::endl;

    CloseWindow();
}

void Window::do_another()
{
	std::cout << "do_another" << std::endl;
}



