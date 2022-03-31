#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui.actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui.actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui.actionSave_As, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui.actionExit, &QAction::triggered, this, &MainWindow::close);

    connect(ui.actionCopy, &QAction::triggered, ui.plainTextEdit, &QPlainTextEdit::copy);
    connect(ui.actionCut, &QAction::triggered, ui.plainTextEdit, &QPlainTextEdit::cut);
    connect(ui.actionPaste, &QAction::triggered, ui.plainTextEdit, &QPlainTextEdit::paste);

    connect(ui.actionSelect_All, &QAction::triggered, ui.plainTextEdit, &QPlainTextEdit::selectAll);
    connect(ui.actionSelect_None, &QAction::triggered, this, &MainWindow::selectNone);

    this->setCentralWidget(ui.plainTextEdit);

    newFile();
    _saved = true;
}

void MainWindow::newFile()
{
    ui.plainTextEdit->clear();
    _filename.clear();
    _saved = false;
    ui.statusBar->showMessage("New File");
}

void MainWindow::openFile()
{
    QString temp = QFileDialog::getOpenFileName(this, "Open file", QString(), "Text files (*.txt);;All files (*.*)");

    if (temp.isEmpty()) return;

    _filename = temp;
    QFile file(_filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        newFile(); 
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui.plainTextEdit->setPlainText(stream.readAll());
    file.close();

    _saved = true;
    ui.statusBar->showMessage(_filename);
}

void MainWindow::saveFile()
{
    if (_filename.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile file(_filename);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui.plainTextEdit->toPlainText();
    file.close();

    _saved = true;
    ui.statusBar->showMessage(_filename);
}

void MainWindow::saveFileAs()
{
    QString temp = QFileDialog::getSaveFileName(this, "Save file", QString(), "Text files (*.txt);;All files (*.*)");
    if (temp.isEmpty()) return;

    _filename = temp;
    saveFile();

}

void MainWindow::selectNone()
{
    QTextCursor cursor = ui.plainTextEdit->textCursor();
    cursor.setPosition(0, QTextCursor::MoveMode::KeepAnchor);
    ui.plainTextEdit->setTextCursor(cursor);
}
