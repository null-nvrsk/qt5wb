#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();

private:
    Ui::MainWindowClass ui;
    QString _filename;
    bool _saved;
};
