#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QListWidgetItem>
#include <QScopedPointer>
#include "dialog.h"
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

    void on_actionToolbar_top_triggered();
    void on_actionToolbar_bottom_triggered();
    void on_actionToolbar_left_triggered();
    void on_actionToolbar_right_triggered();

    void on_actionToolbar_floatable_toggled(bool arg);
    void on_actionToolbar_movable_toggled(bool arg);

    void on_plainTextEdit_textChanged();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionAnimals_triggered();
    void on_actionShapes_triggered();
    void on_actionFood_triggered();


private:
    Ui::MainWindowClass ui;
    QString _filename;
    bool _saved;

    void setupStatusBar();
    void updateStatus(QString message);       
};
