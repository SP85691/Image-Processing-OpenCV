#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include<vector>
using namespace cv; 
using namespace std; 

/////////////////// Images //////////////////////

//int main() 
//{ 
//	string path = "resources/jujutsu.jpg";
//	Mat img = imread(path); imshow("image", img); 
//	waitKey(0);
//	return 0; 
//}

/////////////////// Videos //////////////////////
//
int main()
{
	string path = "Resources/astronaut.mp4";
	VideoCapture cap(path);
	Mat img;

	while(true)
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
	return 0;
}

///////////////// WebCam //////////////////////

//int main()
//{
//	VideoCapture cap(0);
//	Mat img;
//
//	while (true)
//	{
//		cap.read(img);
//		imshow("image", img);
//		waitKey(1);
//	}
//	return 0;
//}