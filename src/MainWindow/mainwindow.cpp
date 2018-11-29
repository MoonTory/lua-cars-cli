#include "mainwindow.h"

namespace Luna {

    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent)
    {
        this->setWindowTitle("Luna Cars");
        this->setFixedSize(800, 600);
    }

    MainWindow::~MainWindow()
    {

    }


}
