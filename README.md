# 目的

尝试调用静态编译的opencv

1. opencv是静态编译，包含调试和发布两版静态库
2. msrt是动态编译
3. tbb是动态链接，相关文件放入opencv_static_lib相应目录
4. 使用msvc2010 32bit保证最广泛的兼容性

# 配置

## Include

1. 采用相对路径，无需修改
2. 包含除QT外所有相关库

## Path

      opencv_static_lib/bin

+ 把目录包含到系统path中
+ 或者添加的项目path中(QCreator)

### TODO

+ 不涉及图像编解码的话ffmpeg是不是可以去掉？
+ tbb库是否可以去掉，或者静态编译？

# 问题

## HighGUI

+ 静态编译时需要包含静态qt才能编译带有qt支持的highgui
+ 静态Qt没有成功编译
+ 使用没有Qt支持的highgui，所以不能使用

### 受影响的函数


      cv::namedWindow
      cv::imshow


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
