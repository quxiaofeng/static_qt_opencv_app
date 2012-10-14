# 目的

尝试调用静态编译的opencv

1. opencv是静态编译，包含调试和发布两版静态库
2. msrt是动态编译，考虑到qt会有msrt
3. 使用msvc2010 32bit保证在PC平台上最广泛的兼容性

# 配置

把Qt 4.8.1 mscv2010 运行时加入系统PATH

## Include

1. 采用相对路径，无需修改
2. 包含除Qt外所有相关库
3. Qt使用的版本
  1. Qt 4.8.1
  2. msvc2010
  3. 32bit

# 方法

## 下载相关软件

1. [CMake 2.8](http://cmake.org/cmake/resources/software.html)，默认安装
2. [QT SDK 1.2.1](http://www.developer.nokia.com/Develop/Qt/Tools/)，默认安装后升级并选定qt 4.8.1 desktop msvc2010
3. [OpenCV 2.4.2](http://sourceforge.net/projects/opencvlibrary/files/latest/download)，解压缩
4. Visual Studio 2010 (C++)

## 编译过程

1. 使用CMake配置OpenCV    
单击configure，共三次，第一次指定目录并选择编译器，第二次选择OpenCV配置，第三次指定qmake    
   + 编译器选择Visual Studio 10 native
   + 勾选 debug_info 使能调试版本
   + 勾选 with_qt 添加 Qt 支持
   + 配置QT_QMAKE_EXECUTABLE为 QtSDK/Desktop/Qt/4.8.1/msvc2010/bin/qmake.exe
   + 勾选with_videoinput 添加 DirectShow 支持
   + 取消 shared_libs 编译静态库
   + 取消 build_with_static_crt, 因为Qt动态链接这个库. 也许静态编译Qt后再修改
   + 取消 with_ffmpeg 因为ffmpeg只有动态库
   + 为节省时间，取消这些: docs/examples/package/perf_tests/tests
5. 单击generate
6. 使用 Visual Studio 2010 打开/output/path/OpenCV.sln
   + 分别选择 Debug/Release Win32 配置
   + 每次先生成 "ALL_BUILD" 约几分钟
   + 然后再生成 "CMakeTargets/INSTALL" 约几秒钟

## 输出结构中有用的文件

      output/path/install
                     bin/*.dll
                     include/*
                     lib/*
                     share/*

## 执行如下清理用Ruby脚本

> *tidy.rb*

      require 'fileutils'

      FileUtils.mv(Dir.glob('share/OpenCV/3rdparty/lib/*.lib'), 'lib/')
      FileUtils.rm_rf('share/')
      FileUtils.rm_rf('doc/')
      FileUtils.rm(Dir.glob('bin/*.exe'), :force=>true)
      FileUtils.rm(Dir.glob('*.cmake'), :force=>true)
      FileUtils.rm(Dir.glob('*~'), :force=>true)

      system("7z a static_opencv_lib.7z lib include")

### tidy.rb依赖的库: Ruby, DevKit, fileutils


## 在Qt项目中添加以下配置以便使用

*假设静态库文件放在 "../opencv_static_lib" 目录*

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

# 问题

## HighGUI

+ HighGUI功能使用Qt支持，相关工程即使自身没有使用也需要在pro文件中加入testlib
+ 而QT += testlib会造成多余的控制台窗口

### 原因

正如[这个帖子](http://comments.gmane.org/gmane.comp.lib.qt.general/30894)提到testlib会强制加入 CONFIG += console

testlib只在highgui中使用了一次

但该处使用涉及到按键事件循环，把Qt的按键事件转换为ASCII码，不知道有没有其他方法替代。

### 解决方法

暂时直接去掉，看起来似乎不影响highgui的功能，另外在我的例子中cv::namedWindow没有按钮。

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

其中的MessageBoxA和GetFocus函数调用出问题，注释掉相关代码(两行)后，可以解决。

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



## OpenCV HighGUI 窗口按钮无图片(Build with Qt)

+ 参见[Bug #2070](http://code.opencv.org/issues/2070)
+ Harald Schmidt给出[Patch #2178](http://code.opencv.org/issues/2178)。不仅解决图标显示问题，同时改进HighGUI的图标显示方式。文件分成两部分。
  1. [Patch 2304](http://code.opencv.org/issues/2304)是需要修改的HighGUI代码。下载四个代码文件后，把头文件和源代码文件分别放到opencv/modules/highgui/include/opencv2/highgui和opencv/modules/highgui/src目录下。
  2. [Patch 2303](http://code.opencv.org/issues/2303)是修改后，新增加功能的示例。

**不好用**，且留待继续测试或者新版修正

### 暂时的解决方式

在没有必要显示像素坐标与颜色的场合，使用没有按钮的窗口。

      cv::namedWindow("Original Image", CV_GUI_NORMAL);


# 测试

## 测试图像放在

      testimages

## 测试程序

1. 用opencv读入图像
2. 用opencv翻转图像
3. 用qt显示图像
4. 用opencv绘图并用qt显示
5. 用qt控制图像中绘图参数

# TODO

静态编译Qt，以实现无dll的单exe
