#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    if(argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<"<image_path>"<<std::endl;
        return -1;
    }

    cv::Mat noisyImage=cv::imread(argv[1]);
    if(noisyImage.empty()){
        std::cerr<<"Error: Couldn't read the image. Check the path and try again";
        return -1;
    }
    cv::imshow("Noisy Image", noisyImage);

    cv::Mat averageBlurred;
    cv::blur(noisyImage, averageBlurred, cv::Size(5, 5));
    cv::imshow("Averaging Blur", averageBlurred);

    cv::Mat gaussianBlurred;
    cv::GaussianBlur(noisyImage, gaussianBlurred, cv::Size(5, 5), 0);
    cv::imshow("Gaussian Blur", gaussianBlurred);

    cv::Mat medianBlurred;
    cv::medianBlur(noisyImage, medianBlurred, 5);
    cv::imshow("Median Blur", medianBlurred);

    cv::waitKey(0);

    return 0;
}