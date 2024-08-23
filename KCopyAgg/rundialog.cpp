#include "rundialog.h"
#include "ui_rundialog.h"
#include <QIcon>

RunDialog::RunDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Icons/RightClickShape/run_ui_icon.png"));
    setWindowTitle("Plant Configuration Advisor:");
}

RunDialog::~RunDialog()
{
    delete ui;
}
