#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;

void asciiGenerator(Mat gray) {
    //                         [0 -- 255]
    std::string density = "    `'\".,_~-=*+:;!?/0#";

    for (int r = 0; r < gray.rows; r++) {
        for (int c = 0; c < gray.cols; c++) {
            float val = static_cast<float>(gray.at<uchar>(r, c));
            int index = round((val / 255) * density.size());

            std::cout << density.at(index);
        }
        std::cout << "\n";
    }

}

int main(int argc, char** argv) {
    VideoCapture cap(0);
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    if (!cap.isOpened()) {
        std::cerr << "[:] Couldn't open camera\n";
        return -1;
    }

    while (1) {
        Mat frame;
        cap >> frame;
        if (frame.empty())
            break;

        Mat dsize;
        Mat gray;
        resize(frame, dsize, Size(64, 48), INTER_LINEAR);

        GaussianBlur(dsize, dsize, Size(3, 3), 0, 0, BORDER_DEFAULT);
        cvtColor(dsize, gray, COLOR_BGR2GRAY);

        imshow("demo", frame);
        char c = (char) waitKey(25);
        if (c == 27)
            break;

        asciiGenerator(gray);
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
