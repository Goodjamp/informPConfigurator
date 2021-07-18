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
    listOfCheckbox.insert(LCD_VALUE_DATE_1, ui->checkBoxPar0);
    listOfCheckbox.insert(LCD_VALUE_TIME_1, ui->checkBoxPar1);
    listOfCheckbox.insert(LCD_VALUE_DATE_2, ui->checkBoxPar2);
    listOfCheckbox.insert(LCD_VALUE_TIME_2, ui->checkBoxPar3);
    listOfCheckbox.insert(LCD_VALUE_DATE_3, ui->checkBoxPar4);
    listOfCheckbox.insert(LCD_VALUE_TIME_3, ui->checkBoxPar5);
    listOfCheckbox.insert(LCD_VALUE_DATE_4, ui->checkBoxPar6);
    listOfCheckbox.insert(LCD_VALUE_TIME_4, ui->checkBoxPar7);
    listOfCheckbox.insert(LCD_VALUE_FRQ, ui->checkBoxPar8);
    listOfCheckbox.insert(LCD_VALUE_TEMPERATURE, ui->checkBoxPar9);
    listOfCheckbox.insert(LCD_VALUE_HUMIDITY, ui->checkBoxPar10);
    listOfCheckbox.insert(LCD_VALUE_PRESSURE, ui->checkBoxPar11);
    listOfCheckbox.insert(LCD_VALUE_PRESSURE_GPA, ui->checkBoxPar12);
    listOfCheckbox.insert(LCD_VALUE_BUI, ui->checkBoxPar13);
}

void lcdStr::setChecked(uint8_t number, bool check)
{
    listOfCheckbox[number]->setChecked(check);
}

void lcdStr::enableControl(bool chekAble, lsdVal value)
{
    if (chekAble == false) {
        listOfCheckbox[value]->setChecked(false);
    }
    listOfCheckbox[value]->setCheckable(chekAble);
    listOfCheckbox[value]->setEnabled(chekAble);
}

bool lcdStr::getChecked(uint8_t number)
{
    return listOfCheckbox[number]->isChecked();
}






