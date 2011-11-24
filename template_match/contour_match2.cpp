#include <stdio.h>
#include "cv.h"
#include "highgui.h"


#ifdef NDEBUG
#pragma comment(lib,"opencv_ml231.lib")
#pragma comment(lib,"opencv_core231.lib")
#pragma comment(lib,"opencv_highgui231.lib")
#pragma comment(lib,"opencv_imgproc231.lib")
#else
#pragma comment(lib,"opencv_ml231d.lib")
#pragma comment(lib,"opencv_core231d.lib")
#pragma comment(lib,"opencv_highgui231d.lib")
#pragma comment(lib,"opencv_imgproc231d.lib")

#endif
int main(int argc, char* argv[]) {
	cvNamedWindow( argv[0], 1 );
	IplImage* img_8uc1 = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
	IplImage* img_edge = cvCreateImage( cvGetSize(img_8uc1), 8, 1 );
	IplImage* img_8uc3 = cvCreateImage( cvGetSize(img_8uc1), 8, 3 );
	cvThreshold( img_8uc1, img_edge, 128, 255, CV_THRESH_BINARY );
    cvShowImage("grey", img_edge);
    cvWaitKey(0);
//    exit(0);
	CvMemStorage* storage = cvCreateMemStorage();
	CvSeq* first_contour = NULL;
	int Nc = cvFindContours(
		img_edge,
		storage,
		&first_contour,
		sizeof(CvContour),
		/* CV_RETR_LIST */ // Try all four values and see what happens
        CV_RETR_EXTERNAL
		);
	int n=0;
	printf( "Total Contours Detected: %d\n", Nc );
    cvShowImage("edge", img_edge);
    cvSaveImage("external.jpg", img_edge);
    cvWaitKey(0);
	for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ) {
		cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
		cvDrawContours(
			img_8uc3,
			c,
			CV_RGB(0xff,0x00,0x00),
			CV_RGB(00,0x00,0xff),
			2, // Try different values of max_level, and see what happens
			1,
			8
			);
		printf("Contour #%d\n", n );
		cvShowImage( argv[0], img_8uc3 );
		printf(" %d elements:\n", c->total );
		for( int i=0; i<c->total; ++i ) {
			CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );
			printf(" (%d,%d)\n", p->x, p->y );
		}
		cvWaitKey(0);
		n++;
	}
	printf("Finished all contours.\n");
	cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
	cvShowImage( argv[0], img_8uc3 );
	cvWaitKey(0);
	cvDestroyWindow( argv[0] );
	cvReleaseImage( &img_8uc1 );
	cvReleaseImage( &img_8uc3 );
	cvReleaseImage( &img_edge );
	return 0;
}
