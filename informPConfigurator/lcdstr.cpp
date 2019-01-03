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

void lcdStr::addLCD(QString name)
{
    ui->labelLCDName->setText(name);
    listOfCheckbox.clear();
    listOfCheckbox.push_back(ui->checkBoxPar0);
    listOfCheckbox.push_back(ui->checkBoxPar1);
    listOfCheckbox.push_back(ui->checkBoxPar2);
    listOfCheckbox.push_back(ui->checkBoxPar3);
    listOfCheckbox.push_back(ui->checkBoxPar4);
    listOfCheckbox.push_back(ui->checkBoxPar5);
    listOfCheckbox.push_back(ui->checkBoxPar6);
    listOfCheckbox.push_back(ui->checkBoxPar7);
    listOfCheckbox.push_back(ui->checkBoxPar8);
    listOfCheckbox.push_back(ui->checkBoxPar9);
    listOfCheckbox.push_back(ui->checkBoxPar10);
    listOfCheckbox.push_back(ui->checkBoxPar11);
    listOfCheckbox.push_back(ui->checkBoxPar12);
}

void lcdStr::setChecked(uint8_t number, bool check)
{
    listOfCheckbox[number]->setChecked(check);
}

bool lcdStr::getChecked(uint8_t number)
{
    return listOfCheckbox[number]->isChecked();
}






