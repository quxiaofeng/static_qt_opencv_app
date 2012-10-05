#-------------------------------------------------
#
# Project created by QtCreator 2012-09-26T00:12:44
#
#-------------------------------------------------

QT       += core gui testlib

TARGET = qtopencv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


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





