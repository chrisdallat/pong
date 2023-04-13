#include "audio.hpp"

Audio::Audio() 
{
    InitAudioDevice();
    m_serve = LoadSound("./audio/Serve.wav");
    if(IsSoundReady(m_serve))
    {
        std::cout << "serve sound is ready!!!!!" << std::endl;
    }  
    m_bounce = LoadSound("./audio/Bounce.wav");
    m_clap = LoadSound("./audio/Clapping.wav");
}

Audio::~Audio() 
{

}

void Audio::play_serve()
{
    PlaySound(m_serve);
}

void Audio::play_bounce()
{
    PlaySound(m_bounce);
}

void Audio::play_clap()
{
    PlaySound(m_clap);
}




