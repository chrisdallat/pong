#include "ball.hpp"

Ball::Ball() 
{
    // m_valid = true;
    // if (m_capture.open(m_camera) == false) 
    // {
    //     std::cout << "Failed to open camera" << std::endl;
    //     m_valid = false;
    // }

    // m_capture.set(cv::CAP_PROP_FRAME_WIDTH, m_video_width);
    // m_capture.set(cv::CAP_PROP_FRAME_HEIGHT, m_video_height);
    // m_mat_original = cv::Mat::zeros(m_video_height, m_video_width, CV_8UC3);
	// m_tracker = cv::TrackerKCF::create();
}

Ball::~Ball() 
{
    // m_capture.release();
    // cv::destroyAllWindows();
}

void Ball::do_something()
{
	std::cout << "do_something" << std::endl;
}

void Ball::do_another()
{
	std::cout << "do_another" << std::endl;
}



