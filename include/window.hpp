#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <string>

class Window
{
    public:
        Window();
        Window(std::string players, std::string powerups, std::string difficulty, std::string points);
        ~Window();

    private:

        int                 m_width = 1000;
        int                 m_height = 600;


};

#endif

