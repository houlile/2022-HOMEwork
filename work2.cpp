#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;  //包含cv命名空间

int main( )
{

    Mat srcImage = imread("/home/lyy/houlile/doc/Girl.jpg");
    imshow("【原始图】Canny边缘检测", srcImage); 	//SS显示原始图
    Mat dstImage,edge,grayImage;	//参数定义

    //【1】创建与src同类型和大小的矩阵(dst)
    dstImage.create( srcImage.size(), srcImage.type() );

    //【2】将原图像转换为灰度图像
    //此句代码的OpenCV2版为：
    //cvtColor( srcImage, grayImage, CV_BGR2GRAY );
    //此句代码的OpenCV3/OpenCV4版为：
    cvtColor( srcImage, grayImage, COLOR_BGR2GRAY );

    //【3】先用使用 3x3内核来降噪
    blur( grayImage, edge, Size(3,3) );

    //【4】运行Canny算子
    Canny( edge, edge, 3, 8,3 );

    //【5】显示效果图
    imshow("【效果图】Canny边缘检测", edge);

    waitKey(0);
}

