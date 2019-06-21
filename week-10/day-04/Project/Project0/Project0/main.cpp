#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat image(1000, 1600, CV_8UC3, CV_RGB(241, 196, 15));

void myMouseCallback(int event, int x, int y, int flags, void* userdata)
{
    if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
        cv::Mat table = image.clone();
        cv::line(table, {table.cols/2, table.rows/2}, {x, y}, CV_RGB(44, 62, 80), 2);
        cv::circle(table, {table.cols/2, table.rows/2}, 15, CV_RGB(231, 76, 60), -1, 8, 0);
        cv::circle(table, {x, y}, 15, CV_RGB(41, 128, 185), -1, 8, 0);
        
        float a = (table.rows/2) - y;
        float b = x - (table.cols/2);
        double resultRad = atan(a/b);
        double resultDeg = (resultRad / 3.1415) * 180;
        
        if (x <= table.cols/2 && y <= table.rows/2){
            resultDeg = 90 + (90 + resultDeg);
        } else if (x <= table.cols/2 && y >= table.rows/2) {
            resultDeg += 180;
        } else if (x >= table.cols/2 && y >= table.rows/2){
            resultDeg = 270 + (90 + resultDeg);
        }
        
        cv::putText(table, std::to_string(resultDeg), {table.cols/2 + 150, table.rows/2 - 20}, cv::FONT_HERSHEY_DUPLEX, 1, CV_RGB(255, 255, 255));
        
        cv::imshow("OpenCV", table);
    }
}

int main(int argc, const char * argv[])
{
    std::cout << cv::getBuildInformation() << std::endl;
    
    cv::line(image, {image.cols/2, image.rows/2}, {image.cols, image.rows/2}, CV_RGB(44, 62, 80), 2);
    cv::circle(image, {image.cols/2, image.rows/2}, 15, CV_RGB(231, 76, 60), -1, 8, 0);
    
    cv::imshow("OpenCV", image);
    cv::setMouseCallback("OpenCV", myMouseCallback);
    cv::waitKey(0);

    
    return 0;
}

