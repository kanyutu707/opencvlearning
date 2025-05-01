#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    if(argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<"<image_path>"<<std::endl;
        return -1;
    }

    cv::Mat image=cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if(image.empty()){
        std::cerr<<"Error: Couldn't read the image. Check the path and try again. "<<std::endl;
        return -1;
    }
    cv::imshow("Original Image", image);

    cv::Mat binaryThresholded;
    cv::threshold(image, binaryThresholded, 127, 255, cv::THRESH_BINARY);
    cv::imshow("Binary Thresholding", binaryThresholded);

    cv::Mat adaptiveThresholded;
    cv::adaptiveThreshold(image, adaptiveThresholded, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
    cv::imshow("Adaptive Thresholding", adaptiveThresholded);

    cv::Mat otsuThresholded;
    cv::threshold(image, otsuThresholded, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imshow("Otsu's Thresholding", otsuThresholded);

    cv::waitKey(0);

    return 0;
}