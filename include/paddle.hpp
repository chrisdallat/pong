#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>

class Paddle 
{
    public:
        Paddle();
        ~Paddle();

        //testing: remove later
        void                do_something();

    private:
        void                do_another();

        //special types
        // cv::Ptr<cv::Tracker> m_tracker;
        // cv::Rect m_tracking_box;
        
        //other private class variables
        int                 m_paddle_length = 640;
        int                 m_paddle_width = 480;


};

#endif
