#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

class Window
{
    public:
        Window();
        ~Window();

        //testing: remove later
        void                start_game();

    private:
        void                do_another();

        //special types
        // cv::Ptr<cv::Tracker> m_tracker;
        // cv::Rect m_tracking_box;
        
        //other private class variables
        int                 m_video_width = 640;
        int                 m_video_height = 480;


};

#endif

