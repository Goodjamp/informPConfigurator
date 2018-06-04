#include "lcdstr.h"
#include "ui_lcdstr.h"

lcdStr::lcdStr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lcdStr)
{
    ui->setupUi(this);
}

lcdStr::~lcdStr()
{
    delete ui;
}

void lcdStr::setNameLCD(QString newName)
{
    ui->labelLCDName->setText(newName);
}
