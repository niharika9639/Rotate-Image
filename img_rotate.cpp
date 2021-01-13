#include<opencv2\highgui.hpp>
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle)                                                      // rotate function returning mat object with parametres imagefile and angle    
{
	Mat dst;                                                                           // Mat object for output image file
	
	Point2f pt(src.cols / 2., src.rows / 2.);                                          // point from where to rotate    
	
	Mat r = getRotationMatrix2D(pt, angle, 1.0);                                       // Mat object for storing after rotation
	
	warpAffine(src, dst, r, Size(src.cols, src.rows));                                 // applie an affine transforation to image.
	
	return dst;                                                                        // returning Mat object for output image file
}

int main(int argc, char** argv)
{
	
	// Read the image file
	Mat src = imread("E:/butterfly.jpg", IMREAD_COLOR);

	Mat dst;
	
	dst = rotate(src, 90);
	
	// Check for failure
	if (src.empty())
	{
		
		cout << "Could not open or find the image" << endl;
		
		cin.get();                                                                     //wait for any key press
		
		return -1;
	
	}
