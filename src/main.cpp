#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

void matchAscii(gray) {

}

int main(int argc, char** argv) {
    std::cout << "harro :3\n";

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "[:] Couldn't open camera\n";
        return -1;
    }

    while (1) {
        Mat frame;
        cap >> frame;

        if (frame.empty())
            break;

        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        imshow("demo", gray);

        waitKey(0);
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
