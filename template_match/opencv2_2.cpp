#include <highgui.h>
#include <iostream>

#ifdef NDEBUG
#pragma comment(lib,"opencv_core231.lib")
#pragma comment(lib, "opencv_highgui231d.lib")
#else
#pragma comment(lib,"opencv_core231d.lib")
#pragma comment(lib, "opencv_highgui231.lib")
#endif
using namespace std;

int main( int argc, char* argv[]) 
{
    cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
    CvCapture *capture = cvCreateFileCapture( argv[1] );
    IplImage *frame;
    if(!capture) { cout << "no capture\n"; exit(-1);}
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) { 
            cout << "no frame\n";
            break;
        }
        cvShowImage( "Example2", frame );
        char c = cvWaitKey(33);
        if( c == 27 ){
            cout << "key int\n";
            break;
        }
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Example2" );
}
