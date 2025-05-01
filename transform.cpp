#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    cv::Mat image = cv::imread(argv[1]);
    if(image.empty()) {
        std::cerr << "Error: Couldn't read the image. Check the path and try again." << std::endl;
        return -1;
    }
    cv::imshow("Original Image", image);

    cv::Point2f source_points[] = { {0, 0}, {image.cols - 1, 0}, {0, image.rows - 1} };
    cv::Point2f destination_points[] = { {0, 50}, {image.cols - 50, 0}, {50, image.rows - 50} };

    cv::Mat affineMatrix = cv::getAffineTransform(source_points, destination_points);
    cv::Mat warpedImage;
    cv::warpAffine(image, warpedImage, affineMatrix, image.size());
    cv::imshow("Warped Image (Affine Transformation)", warpedImage);

    cv::Point2f source_corners[] = { {0, 0}, {image.cols - 1, 0}, {0, image.rows - 1}, {image.cols - 1, image.rows - 1} };
    cv::Point2f destination_corners[] = { {30, 30}, {image.cols - 60, 0}, {0, image.rows - 60}, {image.cols - 1, image.rows - 30} };

    cv::Mat perspectiveMatrix = cv::getPerspectiveTransform(source_corners, destination_corners);
    cv::Mat perspectiveImage;
    cv::warpPerspective(image, perspectiveImage, perspectiveMatrix, image.size());
    cv::imshow("Perspective Change (Non-Affine Transformation)", perspectiveImage);

  
    cv::waitKey(0);
    
    return 0;
}