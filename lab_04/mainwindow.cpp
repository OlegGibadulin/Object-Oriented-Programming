#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = new QVBoxLayout;
    ui->centralWidget->setLayout(layout);
    layout->addWidget(lift.getWidget());
}

MainWindow::~MainWindow()
{
   delete layout;
   delete ui;
}
