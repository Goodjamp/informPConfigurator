#include "waitform.h"
#include "ui_waitform.h"
#include "ui_waitform.h"

waitForm::waitForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waitForm)
{
    ui->setupUi(this);  
    // Disable title bar
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
}

waitForm::~waitForm()
{
    delete ui;
}

