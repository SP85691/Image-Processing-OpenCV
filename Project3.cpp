#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <opencv2/objdetect.hpp>
#include <iostream> 
#include<vector>
using namespace cv;
using namespace std;

/////////////////// Project 3 //////////////////////


int main()
{
	Mat img;
	string path = "Resources/Delhi.jpg";
	//VideoCapture cap(2);
	img = imread(path);
	resize(img, img, Size(), 0.5, 0.5);

	CascadeClassifier plateCascade;
	plateCascade.load("Resources/indian_license_plate.xml");

	if (plateCascade.empty()) { cout << "XML file is not Loaded Correctly" << endl; }

	vector<Rect> plates;
	
	//while (true)
	//{
		//cap.read(img);

		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(0, 255, 255), 2);
			putText(img, to_string(i), Point(137, 262),FONT_HERSHEY_PLAIN, 1.25, Scalar(0, 0, 255), 2);
		}

		imshow("image", img);

		waitKey(0);
	//}
	return 0;
}
