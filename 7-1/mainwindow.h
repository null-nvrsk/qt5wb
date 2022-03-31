#pragma once

#include <QtWidgets/QMainWindow>
#include <QPlainTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionSelect_All_triggered();

private:
    Ui::MainWindowClass ui;
    QString filename;
};
