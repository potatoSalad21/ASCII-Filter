#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    std::cout << "harro :3\n";

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "[:] Couldn't open camera\n";
        return -1;
    }

    Mat frame { };
    while (1) {
        if (!cap.read(frame)) {
            break;
        }

    }

    return 0;
}
