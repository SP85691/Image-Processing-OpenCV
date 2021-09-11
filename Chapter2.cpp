#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include<vector>
using namespace cv;
using namespace std;

/////////////////// Basic Functions //////////////////////
int main() 
{ 
	string path = "Resources/rachel_roth.jpg";
	Mat img = imread(path); imshow("Image", img); 
	Mat imgGray,imgBlur,imgCanny, imgDil, imgErode;
	
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 50, 125);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(4,4));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny",imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erosion", imgErode);
	waitKey(0);
	return 0; 
}
