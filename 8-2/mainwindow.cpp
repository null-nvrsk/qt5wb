#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    setCentralWidget(ui.scrollArea);
    ui.actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui.actionZoom_In->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
    ui.actionZoom_Out->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));

    _lblImage = new QLabel(this); 
    ui.scrollArea->setWidget(_lblImage);
}

void MainWindow::on_actionOpen_triggered()
{
    _path = QFileDialog::getOpenFileName(this, "Open", QString(), "All files (*.*);;Jpg (*.jpg);;Png (*.png)");
    if (_path.isEmpty()) return;

    if (!_img.load(_path))
    {
        QMessageBox::critical(this, "Error", "Could not load the image");
        return;
    }

    _lblImage->setPixmap(_img);
}

void MainWindow::on_actionZoom_In_triggered()
{
    int w = _lblImage->width();
    int h = _lblImage->height();

    w += 50;
    h += 50;
    //w *= 1.1;
    //h *= 1.1;

    _lblImage->resize(w, h);
    _lblImage->setPixmap(_img.scaled(w, h));
}

void MainWindow::on_actionZoom_Out_triggered()
{
    int w = _lblImage->width();
    int h = _lblImage->height();

    w -= 50;
    h -= 50;
    //w /= 1.1;
    //h /= 1.1;

    if (w < 10) w = 10;
    if (h < 10) h = 10;

    _lblImage->resize(w, h);
    _lblImage->setPixmap(_img.scaled(w, h));
}
