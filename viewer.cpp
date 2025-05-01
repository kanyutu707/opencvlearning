#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    if (argc!=2){
        std::cerr<<"Usage: "<<argv[0] << "<image_path>"<<std::endl;
        return -1;
    }

    cv::Mat image=cv::imread(argv[1]);

    if(image.empty()){
        std::cerr<<"Error: Couldn't read the image. Check the path and try again."<<std::endl;
        return -1;
    }

    cv::imshow("Original Image", image);

    cv::Mat grayscaleImage;
    cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY);

    cv::imwrite("grayscale_image.jpg", grayscaleImage);

    cv::imshow("Grayscale Image", grayscaleImage);

    cv::waitKey(0);

    return 0;
}