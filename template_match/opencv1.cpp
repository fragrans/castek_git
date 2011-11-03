#include "highgui.h"

#ifdef NDEBUG
#pragma comment(lib,"opencv_core231.lib")
#pragma comment(lib, "opencv_highgui231d.lib")
#else
#pragma comment(lib,"opencv_core231d.lib")
#pragma comment(lib, "opencv_highgui231.lib")
#endif

int main( int argc, char* argv[]) 
{
    IplImage * img = cvLoadImage( argv[1] );
    cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
    cvShowImage( "Example1", img );
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow( "Example1" );
}
