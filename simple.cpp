#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::Mat image=cv::imread("C:\\Users\\kanyu\\projects\\opencvcourse\\resources\\test.jpg");
    if(image.empty()){
        std::cerr<<"Error loading image! "<<std::endl;
        return -1;
    }
    cv::imshow("Test Image", image);
    cv::waitKey(0);
    return 0;
}