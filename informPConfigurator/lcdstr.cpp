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
    listOfCheckbox.clear();
    listOfCheckbox.push_back(ui->checkBoxPar1);
    listOfCheckbox.push_back(ui->checkBoxPar2);
    listOfCheckbox.push_back(ui->checkBoxPar1);
    listOfCheckbox.push_back(ui->checkBoxPar3);
    listOfCheckbox.push_back(ui->checkBoxPar4);
    listOfCheckbox.push_back(ui->checkBoxPar5);
    listOfCheckbox.push_back(ui->checkBoxPar6);
    listOfCheckbox.push_back(ui->checkBoxPar7);
    listOfCheckbox.push_back(ui->checkBoxPar8);
    listOfCheckbox.push_back(ui->checkBoxPar9);
}
