#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;

Mat src2, src_gray2;
Mat dst2, detected_edges2;

int lowThreshold2 = 10;
const int max_lowThreshold2 = 100;
const int ratio2 = 3;
const int kernel_size2 = 3;
const char* window_name2 = "Edge Map2";

/*static void CannyThreshold002(int, void*)
{
    blur(src_gray, detected_edges, Size(3, 3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow(window_name, dst);
}*/


int testCanny002(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | fruits.jpg | input image}");
    src2 = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR); // Load an image
    
    imshow("src2", src2);
    waitKey(0);


    if (src2.empty())
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    dst2.create(src2.size(), src2.type());
    cvtColor(src2, src_gray2, COLOR_BGR2GRAY);
    namedWindow(window_name2, WINDOW_AUTOSIZE);
    //createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    //CannyThreshold(0, 0);

    blur(src_gray2, detected_edges2, Size(3, 3));
    //Canny(detected_edges2, detected_edges2, lowThreshold2, lowThreshold2 * ratio2, kernel_size2);
    Canny(detected_edges2, detected_edges2, 1,19, kernel_size2);
    dst2 = Scalar::all(0);
    src2.copyTo(dst2, detected_edges2);
    imshow(window_name2, dst2);

    waitKey(0);
    return 0;
}