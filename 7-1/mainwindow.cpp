#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->setCentralWidget(ui.plainTextEdit);
}

void MainWindow::on_actionNew_triggered()
{

    ui.plainTextEdit->clear();
    ui.statusBar->showMessage("");
    filename.clear();
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open a file");
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui.plainTextEdit->setPlainText(stream.readAll());
    file.close();

    ui.statusBar->showMessage(path);
    filename = path;
}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Save file");
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui.plainTextEdit->toPlainText();
    file.close();

    ui.statusBar->showMessage(path);
    filename = path;
}

void MainWindow::on_actionCopy_triggered()
{
    ui.plainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui.plainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui.plainTextEdit->cut();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui.plainTextEdit->selectAll();
}
