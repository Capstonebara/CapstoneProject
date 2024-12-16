#include <iostream>           // For standard input/output
#include <opencv2/opencv.hpp> // Include the OpenCV library

int main() {
  // Open the default camera (0 usually refers to the first USB camera)
  cv::VideoCapture cap(0);

  // Check if the camera is opened successfully
  if (!cap.isOpened()) {
    std::cerr << "Error: Unable to open the camera" << std::endl;
    return -1;
  }

  // Create a window to display the video
  cv::namedWindow("USB Camera", cv::WINDOW_AUTOSIZE);

  while (true) {
    cv::Mat frame; // Matrix to store the captured frame
    cap >> frame;  // Capture a new frame from the camera

    // Check if the frame is empty (end of stream or error)
    if (frame.empty()) {
      std::cerr << "Error: Captured empty frame" << std::endl;
      break;
    }

    cv::imshow("USB Camera", frame);

    // Wait for 1 ms and exit the loop if the user presses 'q'
    if (cv::waitKey(1) == 'q') {
      break;
    }
  }

  // Release the camera and destroy all OpenCV windows
  cap.release();
  cv::destroyAllWindows();

  return 0;
}
