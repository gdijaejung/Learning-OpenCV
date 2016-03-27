
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")

using namespace std;

void main(char argc, char *argv[])
{
	IplImage *src;

	if (argc == 7 && ((src = cvLoadImage(argv[1], 1)) != 0))
	{
		const int x = atoi(argv[2]);
		const int y = atoi(argv[3]);
		const int width = atoi(argv[4]);
		const int height = atoi(argv[5]);
		const int add = atoi(argv[6]);

		cvSetImageROI(src, cvRect(x, y, width, height));
		cvAddS(src, cvScalar(add), src);
		cvResetImageROI(src);

		cvNamedWindow("Roi_Add");
		cvShowImage("Roi_Add", src);
		cvWaitKey();

		cvReleaseImage(&src);
		cvDestroyWindow("Roi_Add");
	}

}
