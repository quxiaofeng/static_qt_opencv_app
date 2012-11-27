# Ŀ��

���Ե��þ�̬������opencv

1. opencv�Ǿ�̬���룬�������Ժͷ������澲̬��
2. msrt�Ƕ�̬���룬���ǵ�qt����msrt
3. ʹ��msvc2010 32bit��֤��PCƽ̨�����㷺�ļ�����

> *[Github Project Page](https://github.com/quxiaofeng/static_qt_opencv_app)*    
> *[Author's Notes](http://www4.comp.polyu.edu.hk/~csxfqu/2012/10/26/opencv.html)*    

# ����

��Qt 4.8.1 mscv2010 ����ʱ����ϵͳPATH

## Include

1. ��������·���������޸�
2. ������Qt���������ؿ�
3. Qtʹ�õİ汾
  1. Qt 4.8.1
  2. msvc2010
  3. 32bit

# ����

## ������������

1. [CMake 2.8](http://cmake.org/cmake/resources/software.html)��Ĭ�ϰ�װ
2. [QT SDK 1.2.1](http://www.developer.nokia.com/Develop/Qt/Tools/)��Ĭ�ϰ�װ��������ѡ��qt 4.8.1 desktop msvc2010
3. [OpenCV 2.4.2](http://sourceforge.net/projects/opencvlibrary/files/latest/download)����ѹ��
4. Visual Studio 2010 (C++)

## ��������

1. ʹ��CMake����OpenCV    
����configure�������Σ���һ��ָ��Ŀ¼��ѡ�����������ڶ���ѡ��OpenCV���ã�������ָ��qmake    
   + ������ѡ��Visual Studio 10 native
   + ��ѡ debug_info ʹ�ܵ��԰汾
   + ��ѡ with_qt ���� Qt ֧��
   + ����QT_QMAKE_EXECUTABLEΪ QtSDK/Desktop/Qt/4.8.1/msvc2010/bin/qmake.exe
   + ��ѡwith_videoinput ���� DirectShow ֧��
   + ȡ�� shared_libs ���뾲̬��
   + ȡ�� build_with_static_crt, ��ΪQt��̬����������. Ҳ����̬����Qt�����޸�
   + ȡ�� with_ffmpeg ��Ϊffmpegֻ�ж�̬��
   + Ϊ��ʡʱ�䣬ȡ����Щ: docs/examples/package/perf_tests/tests
5. ����generate
6. ʹ�� Visual Studio 2010 ����/output/path/OpenCV.sln
   + �ֱ�ѡ�� Debug/Release Win32 ����
   + ÿ�������� "ALL_BUILD" Լ������
   + Ȼ�������� "CMakeTargets/INSTALL" Լ������

## �����ṹ�����õ��ļ�

      output/path/install
                     bin/*.dll
                     include/*
                     lib/*
                     share/*

## ִ������������Ruby�ű�

*tidy.rb*

      require 'fileutils'

      FileUtils.mv(Dir.glob('share/OpenCV/3rdparty/lib/*.lib'), 'lib/')
      FileUtils.rm_rf('share/')
      FileUtils.rm_rf('doc/')
      FileUtils.rm(Dir.glob('bin/*.exe'), :force=>true)
      FileUtils.rm(Dir.glob('*.cmake'), :force=>true)
      FileUtils.rm(Dir.glob('*~'), :force=>true)

      system("7z a static_opencv_lib.7z lib include")

> tidy.rb�����Ŀ�: Ruby, DevKit, fileutils


## ��Qt��Ŀ���������������Ա�ʹ��

*���農̬���ļ����� "../opencv_static_lib" Ŀ¼*

      win32 {
          OPENCVDIR = "../opencv_static_lib"
          exists($$OPENCVDIR) {
              DEFINES += USEOPENCV
              INCLUDEPATH += \
                  $${OPENCVDIR}/include
              DEPENDPATH += \
                  $${OPENCVDIR}/include
              CONFIG(release, debug|release) {
                  LIBS += -L$${OPENCVDIR}/lib \
                      -llibjasper \
                      -llibjpeg \
                      -llibpng \
                      -llibtiff \
                      -lopencv_calib3d242 \
                      -lopencv_contrib242 \
                      -lopencv_core242 \
                      -lopencv_features2d242 \
                      -lopencv_flann242 \
                      -lopencv_gpu242 \
                      -lopencv_highgui242 \
                      -lopencv_imgproc242 \
                      -lopencv_legacy242 \
                      -lopencv_ml242 \
                      -lopencv_nonfree242 \
                      -lopencv_objdetect242 \
                      -lopencv_photo242 \
                      -lopencv_stitching242 \
                      -lopencv_ts242 \
                      -lopencv_video242 \
                      -lopencv_videostab242 \
                      -lzlib
                  PRE_TARGETDEPS += \
                      $${OPENCVDIR}/lib/libjasper.lib \
                      $${OPENCVDIR}/lib/libjpeg.lib \
                      $${OPENCVDIR}/lib/libpng.lib \
                      $${OPENCVDIR}/lib/libtiff.lib \
                      $${OPENCVDIR}/lib/opencv_calib3d242.lib \
                      $${OPENCVDIR}/lib/opencv_contrib242.lib \
                      $${OPENCVDIR}/lib/opencv_core242.lib \
                      $${OPENCVDIR}/lib/opencv_features2d242.lib \
                      $${OPENCVDIR}/lib/opencv_flann242.lib \
                      $${OPENCVDIR}/lib/opencv_gpu242.lib \
                      $${OPENCVDIR}/lib/opencv_highgui242.lib \
                      $${OPENCVDIR}/lib/opencv_imgproc242.lib \
                      $${OPENCVDIR}/lib/opencv_legacy242.lib \
                      $${OPENCVDIR}/lib/opencv_ml242.lib \
                      $${OPENCVDIR}/lib/opencv_nonfree242.lib \
                      $${OPENCVDIR}/lib/opencv_objdetect242.lib \
                      $${OPENCVDIR}/lib/opencv_photo242.lib \
                      $${OPENCVDIR}/lib/opencv_stitching242.lib \
                      $${OPENCVDIR}/lib/opencv_ts242.lib \
                      $${OPENCVDIR}/lib/opencv_video242.lib \
                      $${OPENCVDIR}/lib/opencv_videostab242.lib \
                      $${OPENCVDIR}/lib/zlib.lib
              } else {
                  LIBS += -L$${OPENCVDIR}/lib \
                      -llibjasperd \
                      -llibjpegd \
                      -llibpngd \
                      -llibtiffd \
                      -lopencv_calib3d242d \
                      -lopencv_contrib242d \
                      -lopencv_core242d \
                      -lopencv_features2d242d \
                      -lopencv_flann242d \
                      -lopencv_gpu242d \
                      -lopencv_highgui242d \
                      -lopencv_imgproc242d \
                      -lopencv_legacy242d \
                      -lopencv_ml242d \
                      -lopencv_nonfree242d \
                      -lopencv_objdetect242d \
                      -lopencv_photo242d \
                      -lopencv_stitching242d \
                      -lopencv_ts242d \
                      -lopencv_video242d \
                      -lopencv_videostab242d \
                      -lzlibd
                  PRE_TARGETDEPS += \
                      $${OPENCVDIR}/lib/libjasperd.lib \
                      $${OPENCVDIR}/lib/libjpegd.lib \
                      $${OPENCVDIR}/lib/libpngd.lib \
                      $${OPENCVDIR}/lib/libtiffd.lib \
                      $${OPENCVDIR}/lib/opencv_calib3d242d.lib \
                      $${OPENCVDIR}/lib/opencv_contrib242d.lib \
                      $${OPENCVDIR}/lib/opencv_core242d.lib \
                      $${OPENCVDIR}/lib/opencv_features2d242d.lib \
                      $${OPENCVDIR}/lib/opencv_flann242d.lib \
                      $${OPENCVDIR}/lib/opencv_gpu242d.lib \
                      $${OPENCVDIR}/lib/opencv_highgui242d.lib \
                      $${OPENCVDIR}/lib/opencv_imgproc242d.lib \
                      $${OPENCVDIR}/lib/opencv_legacy242d.lib \
                      $${OPENCVDIR}/lib/opencv_ml242d.lib \
                      $${OPENCVDIR}/lib/opencv_nonfree242d.lib \
                      $${OPENCVDIR}/lib/opencv_objdetect242d.lib \
                      $${OPENCVDIR}/lib/opencv_photo242d.lib \
                      $${OPENCVDIR}/lib/opencv_stitching242d.lib \
                      $${OPENCVDIR}/lib/opencv_ts242d.lib \
                      $${OPENCVDIR}/lib/opencv_video242d.lib \
                      $${OPENCVDIR}/lib/opencv_videostab242d.lib \
                      $${OPENCVDIR}/lib/zlibd.lib
              }
              message("OpenCV libraries found in $${OPENCVDIR}")
          } else {
              message("OpenCV libraries not found.")
          }
      }

# ����

## HighGUI

+ HighGUI����ʹ��Qt֧�֣����ع��̼�ʹ����û��ʹ��Ҳ��Ҫ��pro�ļ��м���testlib
+ ��QT += testlib�����ɶ����Ŀ���̨����

### ԭ��

����[��������](http://comments.gmane.org/gmane.comp.lib.qt.general/30894)�ᵽtestlib��ǿ�Ƽ��� CONFIG += console

testlibֻ��highgui��ʹ����һ��

���ô�ʹ���漰�������¼�ѭ������Qt�İ����¼�ת��ΪASCII�룬��֪����û����������������

### ��������

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

## TIFF lib

���е�MessageBoxA��GetFocus�������ó����⣬ע�͵����ش���(����)�󣬿��Խ�����

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
+ Harald Schmidt����[Patch #2178](http://code.opencv.org/issues/2178)����������ͼ����ʾ���⣬ͬʱ�Ľ�HighGUI��ͼ����ʾ��ʽ���ļ��ֳ������֡�
  1. [Patch 2304](http://code.opencv.org/issues/2304)����Ҫ�޸ĵ�HighGUI���롣�����ĸ������ļ��󣬰�ͷ�ļ���Դ�����ļ��ֱ��ŵ�opencv/modules/highgui/include/opencv2/highgui��opencv/modules/highgui/srcĿ¼�¡�
  2. [Patch 2303](http://code.opencv.org/issues/2303)���޸ĺ��������ӹ��ܵ�ʾ����

**������**���������������Ի����°�����

### ��ʱ�Ľ�����ʽ

��û�б�Ҫ��ʾ������������ɫ�ĳ��ϣ�ʹ��û�а�ť�Ĵ��ڡ�

      cv::namedWindow("Original Image", CV_GUI_NORMAL);


# ����

## ����ͼ������

      testimages

## ���Գ���

1. ��opencv����ͼ��
2. ��opencv��תͼ��
3. ��qt��ʾͼ��
4. ��opencv��ͼ����qt��ʾ
5. ��qt����ͼ���л�ͼ����

# TODO

��̬����Qt����ʵ����dll�ĵ�exe
