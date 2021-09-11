#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include<vector>

using namespace cv;
using namespace std;

/////////////////// Color Detection //////////////////////

Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

VideoCapture cap(2);
Mat img;

int main()
{
	namedWindow("TrackBars", (640, 200)); //Create Window
	createTrackbar("Hue Min", "TrackBars", &hmin, 179);
	createTrackbar("Hue Max", "TrackBars", &hmin, 179);
	createTrackbar("Sat Min", "TrackBars", &smin, 255);
	createTrackbar("Sat Max", "TrackBars", &smax, 255);
	createTrackbar("Value Min", "TrackBars", &vmin, 255);
	createTrackbar("Value Max", "TrackBars", &vmax, 255);

	while (true)
	{
		cap.read(img);

		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		
		inRange(imgHSV, lower, upper, mask);
		//Bitwise_and(img, img, imgColor, mask = mask);
		cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;
		// I show hmin, smin, vmin, hmax, smax, vmax;

		
		imshow("Image", img);
		imshow("Image Mask", mask);
		//imshow("Image Color", imgColor);

		waitKey(1);
	}
	return 0;
}

