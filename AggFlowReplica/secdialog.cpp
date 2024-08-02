#include "secdialog.h"
#include "ui_secdialog.h"

#include <QPushButton>
#include <QStatusBar>
#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    setWindowTitle("Adjust Apron Feeder");

    ui->comboBoxUnits->addItem("kg/MT");
    ui->comboBoxUnits->addItem("lbs/ton");


}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButtonAddRow_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}

void SecDialog::on_pushButtonDeleteRow_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if(currentRow >= 0)
    {
        ui->tableWidget->removeRow(currentRow);
    }
    else
    {
        QMessageBox::warning(this,"Warning","Select a row to delete");
    }
}


