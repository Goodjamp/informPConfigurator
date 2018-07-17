#include "waitform.h"
#include "ui_waitform.h"
#include "ui_waitform.h"
#include "QPushButton"

waitForm::waitForm(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::waitForm)
{
    ui->setupUi(this);  
    // Disable title bar
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);

    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
}


waitForm::~waitForm()
{
    delete ui;
}
