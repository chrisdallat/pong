#include "window.hpp"
#include "game.hpp"
#include "raylib.h"

Window::Window() 
{

}

Window::Window(std::string players, std::string powerups, std::string difficulty, std::string points)
{
    InitWindow(m_width, m_height, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game = Game(players, powerups, difficulty, points);

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
            DrawRectangle(GetScreenWidth()/2, 40, 2, GetScreenHeight(), WHITE);
            if((m_winner = game.run_game()) > 0)
                break;
		EndDrawing();
	}
}

Window::~Window() 
{
    CloseWindow();
}

int Window::get_winner()
{
    return m_winner;
}



