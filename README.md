# 目的

尝试调用静态编译的opencv

1. opencv是静态编译，包含调试和发布两版静态库
2. msrt是动态编译，考虑到qt会有msrt
3. 使用msvc2010 32bit保证最广泛的兼容性

# 配置

**Most Important** 

      QT += testlib

Add this line to the pro file

## Include

1. 采用相对路径，无需修改
2. 包含除Qt外所有相关库
3. Qt使用的版本
  1. Qt 4.8.1
  2. msvc2010
  3. 32bit


# 问题

## HighGUI

+ HighGUI功能使用Qt支持，相关工程即使自身没有使用也需要在pro文件中加入testlib

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

#### 暂时的解决方式

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
