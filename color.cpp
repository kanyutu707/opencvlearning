#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    if (argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<"<image_path>"<<std::endl;
        return -1;
    }

    cv::Mat image=cv::imread(argv[1]);
    if(image.empty()){
        std::cerr<<"Error: Couldn't read the image. Check the path and try again. "<<std::endl;
        return -1;
    }

    cv::Mat grayscale;
    cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
    cv::imshow("Grayscale", grayscale);

    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    cv::imshow("HSV", hsv);

    cv::Mat lab;
    cv::cvtColor(image, lab, cv::COLOR_BGR2Lab);
    cv::imshow("LAB", lab);

    cv::waitKey(0);

    return 0;
}