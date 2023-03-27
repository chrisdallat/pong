#include "window.hpp"
#include "game.hpp"
#include "raylib.h"

Window::Window() 
{
    std::cout << "Initialising Window Object" << std::endl;

    InitWindow(m_width, m_height, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game;

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
            DrawRectangle(GetScreenWidth()/2, 40, 2, GetScreenHeight(), WHITE);

            game.run_game();
		EndDrawing();
	}
}

Window::~Window() 
{
    std::cout << "Closing Window: Deconstructor" << std::endl;

    CloseWindow();
}



