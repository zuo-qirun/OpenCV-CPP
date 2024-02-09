#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // 打开摄像头
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "无法打开摄像头" << endl;
        return -1;
    }
    // 创建窗口
    namedWindow("摄像头画面", WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            cout << "无法捕获摄像头画面" << endl;
            break;
        }

        imshow("摄像头画面", frame);

        // 按下ESC键退出
        if (waitKey(30) == 27)
        {
            break;
        }
    }

    // 释放资源
    cap.release();
    destroyAllWindows();

    return 0;
}