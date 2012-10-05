#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_flip->setEnabled(false);
    opencvDispWindow = false;
    ui->checkBox_disp->setChecked(opencvDispWindow);
    center.x=240;
    center.y=180;
    ui->spinBox_centerX->setValue(center.x);
    ui->spinBox_centerY->setValue(center.y);
    innerRadius = 80;
    ui->spinBox_inR->setValue(innerRadius);
    outerRadius = 180;
    ui->spinBox_outR->setValue(outerRadius);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    "*",
                                                    tr("Image Files (*.png *.jpg *.bmp"));
    if (fileName.isNull()) return;
    image = cv::imread(fileName.toAscii().data());
    if (image.data) ;
    else return;
    ui->textBrowser_log->append(tr("image file: ")+fileName+tr(" loaded successfully\n"));
    ui->pushButton_flip->setEnabled(true);
    cv::Mat tempImage = image.clone();
    cv::cvtColor(tempImage,tempImage,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(tempImage.data),
                        tempImage.cols,
                        tempImage.rows,
                        QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    tempImage.release();
    ui->label->resize(ui->label->pixmap()->size());
    if (opencvDispWindow) {
        cv::namedWindow("Original Image");
        cv::imshow("Original Image", image);
    }
    drawFov(image);
}

void MainWindow::on_pushButton_flip_clicked()
{
    if (image.data);
    else{
        ui->pushButton_flip->setEnabled(false);
        return;
    }
    cv::flip(image,image,1);
    cv::Mat tempImage = image.clone();
    cv::cvtColor(tempImage,tempImage,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(tempImage.data),
                        tempImage.cols,
                        tempImage.rows,
                        QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    tempImage.release();
    ui->label->resize(ui->label->pixmap()->size());
    if (opencvDispWindow) {
        cv::namedWindow("Processed Image");
        cv::imshow("Processed Image", image);
    }
    drawFov(image);
}

void MainWindow::on_checkBox_disp_stateChanged(int arg1)
{
    opencvDispWindow = arg1 == 2;
    if (opencvDispWindow);
    else
        cv::destroyAllWindows();
    // 0 unchecked, 1 partially checked, 2 checked.
}

void MainWindow::on_spinBox_centerX_valueChanged(int arg1)
{
    center.x = arg1;
    if (image.data)
        drawFov(image);
}

void MainWindow::on_spinBox_centerY_valueChanged(int arg1)
{
    center.y = arg1;
    if (image.data)
        drawFov(image);
}

void MainWindow::on_spinBox_inR_valueChanged(int arg1)
{
    innerRadius = arg1;
    if (image.data)
        drawFov(image);
}

void MainWindow::on_spinBox_outR_valueChanged(int arg1)
{
    outerRadius = arg1;
    if (image.data)
        drawFov(image);
}

void MainWindow::drawFov(const cv::Mat& im)
{
    cv::Mat drawnImage = im.clone();
    if (drawnImage.channels() == 1) {
        cv::cvtColor(drawnImage,drawnImage,CV_GRAY2RGB);
    } else if (drawnImage.channels() == 3) {
        cv::cvtColor(drawnImage,drawnImage,CV_BGR2RGB);
    }
    int thickness = 2;
    cv::Scalar fillColor = CV_RGB(0,0,255);
    cv::circle(drawnImage, center, thickness, fillColor, thickness, 8, 0);
    cv::circle(drawnImage, center, innerRadius, fillColor, thickness, 8, 0);
    cv::circle(drawnImage, center, outerRadius, fillColor, thickness, 8, 0);
    QImage img = QImage((const unsigned char*)(drawnImage.data),
                        drawnImage.cols,
                        drawnImage.rows,
                        QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    drawnImage.release();
    ui->label->resize(ui->label->pixmap()->size());
    return;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    cv::destroyAllWindows();
    event->accept();
}
