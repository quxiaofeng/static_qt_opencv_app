# Ŀ��

���Ե��þ�̬�����opencv

1. opencv�Ǿ�̬���룬�������Ժͷ������澲̬��
2. msrt�Ƕ�̬���룬���ǵ�qt����msrt
3. ʹ��msvc2010 32bit��֤��㷺�ļ�����

# ����

**Most Important** 

      QT += testlib

Add this line to the pro file

## ������

QT += testlib����ɶ���Ŀ���̨����

### ԭ��

����[�������](http://comments.gmane.org/gmane.comp.lib.qt.general/30894)�ᵽtestlib��ǿ�Ƽ��� CONFIG += console

testlibֻ��highgui��ʹ����һ��

���ô�ʹ���漰�������¼�ѭ������Qt�İ����¼�ת��ΪASCII�룬��֪����û���������������
��ʱֱ��ȥ�����������ƺ���Ӱ��highgui�Ĺ��ܣ��������ҵ�������cv::namedWindowû�а�ť��

*opencv/modules/highgui/src/windows_QT.cpp*

      void CvWindow::keyPressEvent(QKeyEvent *evnt)
      {
          ...
          // Qt::Key qtkey = static_cast<Qt::Key>(key);
          // char asciiCode = QTest::keyToAscii(qtkey);
          // if (asciiCode != 0)
          //     key = static_cast<int>(asciiCode);
          // else
              key = evnt->nativeVirtualKey(); //same codes as returned by GTK-based backend
          ...
      }



*opencv/modules/highgui/src/windows_QT.h*

      // #include <QtTest/QTest>

## Include

1. �������·���������޸�
2. ������Qt��������ؿ�
3. Qtʹ�õİ汾
  1. Qt 4.8.1
  2. msvc2010
  3. 32bit


# ����

## HighGUI

+ HighGUI����ʹ��Qt֧�֣���ع��̼�ʹ����û��ʹ��Ҳ��Ҫ��pro�ļ��м���testlib

## TIFF lib

���е�MessageBoxA��GetFocus�������ó����⣬ע�͵���ش���(����)�󣬿��Խ����

*opencv/3rdparty/libtiff/tif_win32.c*


      static void
      Win32WarningHandler(const char* module, const char* fmt, va_list ap)
      {
          ...
          //MessageBoxA(GetFocus(), szTmp, szTitle, MB_OK | MB_ICONINFORMATION);
          ...
      }

      static void
      Win32ErrorHandler(const char* module, const char* fmt, va_list ap)
      {
          ...
          //MessageBoxA(GetFocus(), szTmp, szTitle, MB_OK | MB_ICONEXCLAMATION);
          ...
      }



## OpenCV HighGUI ���ڰ�ť��ͼƬ(Build with Qt)

+ �μ�[Bug #2070](http://code.opencv.org/issues/2070)
+ Harald Schmidt����[Patch #2178](http://code.opencv.org/issues/2178)���������ͼ����ʾ���⣬ͬʱ�Ľ�HighGUI��ͼ����ʾ��ʽ���ļ��ֳ������֡�
  1. [Patch 2304](http://code.opencv.org/issues/2304)����Ҫ�޸ĵ�HighGUI���롣�����ĸ������ļ��󣬰�ͷ�ļ���Դ�����ļ��ֱ�ŵ�opencv/modules/highgui/include/opencv2/highgui��opencv/modules/highgui/srcĿ¼�¡�
  2. [Patch 2303](http://code.opencv.org/issues/2303)���޸ĺ������ӹ��ܵ�ʾ����

**������**���������������Ի����°�����

#### ��ʱ�Ľ����ʽ

��û�б�Ҫ��ʾ������������ɫ�ĳ��ϣ�ʹ��û�а�ť�Ĵ��ڡ�

      cv::namedWindow("Original Image", CV_GUI_NORMAL);


# ����

## ����ͼ�����

      testimages

## ���Գ���

1. ��opencv����ͼ��
2. ��opencv��תͼ��
3. ��qt��ʾͼ��
4. ��opencv��ͼ����qt��ʾ
5. ��qt����ͼ���л�ͼ����

# TODO

��̬����Qt����ʵ����dll�ĵ�exe
