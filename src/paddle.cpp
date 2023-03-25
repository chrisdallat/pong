#include "../include/paddle.hpp"

Paddle::Paddle() 
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

Paddle::~Paddle() 
{
    // m_capture.release();
    // cv::destroyAllWindows();
}

void Paddle::do_something()
{
	std::cout << "do_something" << std::endl;
}

void Paddle::do_another()
{
	std::cout << "do_another" << std::endl;
}



