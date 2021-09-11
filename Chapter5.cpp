#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include<vector>

using namespace cv;
using namespace std;

/////////////////// Draw Shapes and Text //////////////////////

float w = 300, h = 350;
Mat matrix, imgWrap;

int main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	
	Point2f src[4] = { {742,386},{1023,436},{648,707},{966,780} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWrap, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Wrap", imgWrap);

	waitKey(0);
	return 0;
}

