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
    setupStatusBar();

    newFile();
    _saved = true;
}

void MainWindow::newFile()
{
    ui.plainTextEdit->clear();
    _filename.clear();
    _saved = false;
    //ui.statusBar->showMessage("New File");
    updateStatus("New file");
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
    // ui.statusBar->showMessage(_filename);
    updateStatus(_filename);
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
    //ui.statusBar->showMessage(_filename);
    updateStatus(_filename);
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
    int pos = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(pos, QTextCursor::MoveMode::KeepAnchor);
    ui.plainTextEdit->setTextCursor(cursor);
}

void MainWindow::on_actionToolbar_top_triggered()
{
    addToolBar(Qt::ToolBarArea::TopToolBarArea, ui.toolBar);
}

void MainWindow::on_actionToolbar_bottom_triggered()
{
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, ui.toolBar);
}

void MainWindow::on_actionToolbar_left_triggered()
{
    addToolBar(Qt::ToolBarArea::LeftToolBarArea, ui.toolBar);
}

void MainWindow::on_actionToolbar_right_triggered()
{
    addToolBar(Qt::ToolBarArea::RightToolBarArea, ui.toolBar);
}

void MainWindow::on_actionToolbar_floatable_toggled(bool arg)
{
    ui.toolBar->setFloatable(arg);
}

void MainWindow::on_actionToolbar_movable_toggled(bool arg)
{
    ui.toolBar->setMovable(arg);
}

void MainWindow::on_plainTextEdit_textChanged()
{
    _saved = false;
    if (_filename.isEmpty())
    {
        updateStatus("New file");
    }
    else
    {
        updateStatus("*" + _filename);
    }
}

void MainWindow::setupStatusBar()
{
    QLabel* lblIcon = new QLabel(this);
    lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
    ui.statusBar->addWidget(lblIcon);

    QLabel* lblStatus = new QLabel(this);
    lblStatus->setText("Not saved:");
    ui.statusBar->addWidget(lblStatus);

    QLabel* lblFile = new QLabel(this);
    lblFile->setText("New");
    ui.statusBar->addWidget(lblFile);
}

void MainWindow::updateStatus(QString message)
{
    foreach(QObject* obj, ui.statusBar->children())
    {
        qDebug() << obj;
    }

    QLabel* lblIcon = qobject_cast<QLabel*>(ui.statusBar->children().at(1));
    QLabel* lblStatus = qobject_cast<QLabel*>(ui.statusBar->children().at(2));
    QLabel* lblFile = qobject_cast<QLabel*>(ui.statusBar->children().at(4));

    if (_saved)
    {
        lblIcon->setPixmap(QPixmap(":/files/images/save.png"));
        lblStatus->setText("Saved:");
    }
    else
    {
        lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
        lblStatus->setText("Not saved:");
    }

    lblFile->setText(_filename);
}
