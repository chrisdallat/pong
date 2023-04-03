#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"

Game::Game() 
{
    m_player1 = Paddle(PLAYER_1);
    m_player2 = Paddle(PLAYER_2);
    m_game_points = 0;
}

Game::~Game() 
{
    std::cout << "Closing Pong!" << std::endl;
}

void Game::run_game()
{   
    if(!m_in_play)
        serve();

    m_ball.move_ball();
    m_player1.move_paddle(PLAYER_1);

    if(m_ai_player)
        ai_paddle();
    else
        m_player2.move_paddle(PLAYER_2);

    collision_detect();
    keep_score();
}

void Game::collision_detect()
{
    // player 1 collision detection
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player1.getRect()))
    {
        alter_trajectory(1);
        m_ball.set_xspeed(m_ball.get_xspeed() * -1);
    }

    // player 2 collision detection
    if(CheckCollisionCircleRec(Vector2{m_ball.get_xpos(), m_ball.get_ypos()}, m_ball.get_radius(), m_player2.getRect()))
    {
        alter_trajectory(2);
        m_ball.set_xspeed(m_ball.get_xspeed() * -1); 
    }
}       

void Game::alter_trajectory(int player)
{
    if(m_ball.get_yspeed() == 0)
        m_ball.set_yspeed(5);

    //player 1 going with the ball angle
    if(player == 1 &&(m_player1.get_last_key() == KEY_W && m_ball.get_yspeed() < 0 || m_player1.get_last_key() == KEY_S && m_ball.get_yspeed() > 0))
        change_speeds(0.8, 1.4);
    //player 1 going against ball angle
    if(player == 1 &&(m_player1.get_last_key() == KEY_S && m_ball.get_yspeed() < 0 || m_player1.get_last_key() == KEY_W && m_ball.get_yspeed() > 0))
        change_speeds(1.5, -0.6);
    //player 2 going with ball angle
    if(player == 2 &&(m_player2.get_last_key() == KEY_UP && m_ball.get_yspeed() < 0 || m_player2.get_last_key() == KEY_DOWN && m_ball.get_yspeed() > 0))
        change_speeds(0.8, 1.4);
    //player 2 going against ball angle
    if(player == 2 &&(m_player2.get_last_key() == KEY_DOWN && m_ball.get_yspeed() < 0 || m_player2.get_last_key() == KEY_UP && m_ball.get_yspeed() > 0))
        change_speeds(1.5, -0.6);
}

void Game::change_speeds(float x, float y)
{
    float x_new = m_ball.get_xspeed() * x;
    float y_new = m_ball.get_yspeed() * y;
    if((y_new / x_new) < 3 && (y_new / x_new) > -3)
    {
        m_ball.set_xspeed(x_new);
        m_ball.set_yspeed(y_new);
    }
}

void Game::keep_score()
{
    std::string score1 = std::to_string(m_ball.get_score1());
    std::string score2 = std::to_string(m_ball.get_score2());
    std::string score_string = score1 + " : " + score2;
    int offset = (GetScreenWidth() / 2) - (MeasureText(score_string.c_str(), 20) / 2);
    DrawText(score_string.c_str(), offset, 10, 20, WHITE);

    if((m_ball.get_score1() + m_ball.get_score2()) > m_game_points)
    {
        m_in_play = false;
        m_game_points++;
    }
}

void Game::serve()
{
    if(m_last_serve == 2)
    {
        m_ball.serve_ball_position(m_player1.get_xpos() + DEFAULT_BALL_RADIUS + DEFAULT_PADDLE_WIDTH, m_player1.get_ypos() + (DEFAULT_PADDLE_LENGTH/2));
        if(IsKeyDown(KEY_SPACE))
        {
            m_ball.set_xspeed(DEFAULT_BALL_XSPEED);
            serve_direction(PLAYER_1);
            m_in_play = true;
            m_last_serve = 1;
        }
    }
    else if (m_last_serve == 1 && !m_ai_player)
    {
        m_ball.serve_ball_position(m_player2.get_xpos() - DEFAULT_BALL_RADIUS, m_player2.get_ypos() + (DEFAULT_PADDLE_LENGTH/2));
        if(IsKeyDown(KEY_ENTER))
        {
            m_ball.set_xspeed(-(DEFAULT_BALL_XSPEED));
            serve_direction(PLAYER_2);
            m_in_play = true;
            m_last_serve = 2;
        }
    }
    else if (m_last_serve == 1 && m_ai_player)
        ai_serve();
}

void Game::serve_direction(int player)
{
    if(player == 1)
    {
        if(m_player1.get_last_key() == KEY_W)
            m_ball.set_yspeed(-(DEFAULT_BALL_YSPEED));
        if(m_player1.get_last_key() == KEY_S)
            m_ball.set_yspeed(DEFAULT_BALL_YSPEED);
    }
    if(player == 2)
    {
        if(m_player2.get_last_key() == KEY_UP)
            m_ball.set_yspeed(-(DEFAULT_BALL_YSPEED));
        if(m_player2.get_last_key() == KEY_DOWN)
            m_ball.set_yspeed(DEFAULT_BALL_YSPEED);
    }
}

void Game::ai_paddle()
{
    m_player2.draw_paddle();
    if (m_ball.get_ypos() < m_player2.get_ypos() - 100 + (m_player2.get_length() / 2) && rand() % m_difficulty == 1) 
        m_player2.set_ypos(m_player2.get_yspeed() * -3);
    else if (m_ball.get_ypos() < m_player2.get_ypos() + (m_player2.get_length() / 2) && rand() % m_difficulty == 1) 
        m_player2.set_ypos(m_player2.get_yspeed() * -2);
    else if (m_ball.get_ypos() > m_player2.get_ypos() + 100 + (m_player2.get_length() / 2) && rand() % m_difficulty == 1)
        m_player2.set_ypos(m_player2.get_yspeed() * 3);
    else if (m_ball.get_ypos() > m_player2.get_ypos() + (m_player2.get_length() / 2) && rand() % m_difficulty == 1)
        m_player2.set_ypos(m_player2.get_yspeed() * 2);
}

void Game::ai_serve()
{
    m_ball.serve_ball_position(m_player2.get_xpos() - DEFAULT_BALL_RADIUS, m_player2.get_ypos() + (DEFAULT_PADDLE_LENGTH/2));
    m_ball.set_xspeed(-(DEFAULT_BALL_XSPEED));
    if(rand() % 1 == 1)
        m_ball.set_yspeed(-(DEFAULT_BALL_YSPEED));
    else
        m_ball.set_yspeed(DEFAULT_BALL_YSPEED);
    m_in_play = true;
    m_last_serve = 2;
}




