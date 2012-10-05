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
4. 没有包含tiff库

# 问题

## HighGUI

+ HighGUI功能使用Qt库，需要在pro文件中加入testlib

### 受影响的函数


      cv::namedWindow
      cv::imshow

以及其他相关窗口显示函数

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
