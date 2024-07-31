#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->statusbar->addPermanentWidget(spacer, 1);

    QPushButton *pushbtn1 = new QPushButton("Save");
    ui->statusbar->addWidget(pushbtn1);

    QPushButton *pushbtn2 = new QPushButton("Cancel");
    ui->statusbar->addWidget(pushbtn2);

    QPushButton *pushbtn3 = new QPushButton("Help");
    ui->statusbar->addWidget(pushbtn3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

