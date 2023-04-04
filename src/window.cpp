#include "window.hpp"
#include "game.hpp"
#include "raylib.h"

Window::Window() 
{
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

Window::Window(std::string players, std::string powerups, std::string difficulty, std::string points)
{
    std::cout << "creating class" << std::endl;
    InitWindow(m_width, m_height, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game = Game(players, powerups, difficulty, points);

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
            DrawRectangle(GetScreenWidth()/2, 40, 2, GetScreenHeight(), WHITE);
            if(game.run_game() > 0)
            {
                std::cout << "Winner is: PLAYER " << game.get_winner() << std::endl;
                break;
            }

		EndDrawing();
	}
}

Window::~Window() 
{
    CloseWindow();
}



