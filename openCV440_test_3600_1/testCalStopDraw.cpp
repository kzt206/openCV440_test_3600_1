#include <opencv2/opencv.hpp>
#include <iostream>

#include <chrono>
#include <thread>

int testCalStopDraw(){

    cv::Mat image(500,500, CV_8UC3);
	image = cv::Scalar(255, 255, 255);
	//image = cv::imread("D:\\OneDrive\\Programing\\openCV\\lena.png");


	while (1) {
		std::cout << "1 " << std::endl;

	    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "2 " << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));



		cv::imshow("showing", image); // ウィンドウに動画を表示する
		if (cv::waitKey(1) == 'q') break; //qを押すと終了

	}
	return 0;

}