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

int main(int argc, char* argv[])
{
    IplImage* sample=0;
    IplImage* model=0;

    if((sample=cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE))== 0)
    {
        printf("error parameter 1.\n");
        exit(0);
    }
    if((model=cvLoadImage(argv[2], CV_LOAD_IMAGE_GRAYSCALE))== 0)
    {
        printf("error parameter 2.\n");
        exit(0);
    }
    cvNamedWindow("model");
    cvNamedWindow("sample");
    cvShowImage("sample",sample);
    cvShowImage("model",model);
    cvWaitKey(0);

    double similarity=cvMatchShapes(sample,model,CV_CONTOURS_MATCH_I3);
    printf("The similarity is %.20lf\n",similarity);

    cvDestroyWindow("model");
    cvDestroyWindow("sample");
    cvReleaseImage(&sample);
    cvReleaseImage(&model);

    return 0;
}
