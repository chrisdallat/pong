#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>

class Ball
{
    public:
        Ball();
        ~Ball();

        //testing: remove later
        void                do_something();

    private:
        void                do_another();

        //special types
        // cv::Ptr<cv::Tracker> m_tracker;
        // cv::Rect m_tracking_box;
        
        //other private class variables
        int                 m_direction = 5;
        int                 m_size = 10;


};

#endif
