#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QCloseEvent>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_flip_clicked();

    void on_checkBox_disp_stateChanged(int arg1);

    void on_spinBox_centerX_valueChanged(int arg1);

    void on_spinBox_centerY_valueChanged(int arg1);

    void on_spinBox_inR_valueChanged(int arg1);

    void on_spinBox_outR_valueChanged(int arg1);


private:
    Ui::MainWindow *ui;
    cv::Mat image;
    bool opencvDispWindow;
    cv::Point center;
    double innerRadius;
    double outerRadius;
    void drawFov(const cv::Mat& im);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
