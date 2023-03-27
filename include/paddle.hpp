#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>

class Paddle 
{
    public:
        Paddle();
        ~Paddle();

        //testing: remove later

    private:
        int                 get_paddle_size();
        void                set_paddle_size();

        //special types
        // cv::Ptr<cv::Tracker> m_tracker;
        // cv::Rect m_tracking_box;
        
        //other private class variables
        int                 m_paddle_size = 100;
        int                 m_paddle_width = 5;


};

#endif
