#ifndef AUDIO_HPP
#define AUDIO_HPP



#include <iostream>
#include "raylib.h"

class Audio
{
    public:
        Audio();
        ~Audio();

        void    play_serve();
        void    play_bounce();
        void    play_clap();

    

    private:

        Sound m_serve;
        Sound m_bounce;
        Sound m_clap;
        

};

#endif
