#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // ������ͷ
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "�޷�������ͷ" << endl;
        return -1;
    }
    // ��������
    namedWindow("����ͷ����", WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            cout << "�޷���������ͷ����" << endl;
            break;
        }

        imshow("����ͷ����", frame);

        // ����ESC���˳�
        if (waitKey(30) == 27)
        {
            break;
        }
    }

    // �ͷ���Դ
    cap.release();
    destroyAllWindows();

    return 0;
}