#include "clockconfig.h"
#include "ui_clockconfig.h"

clockConfig::clockConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clockConfig)
{
    ui->setupUi(this);
}

clockConfig::~clockConfig()
{
    delete ui;
}


void clockConfig::setHorseRange(QStringList items)
{
    ui->comboBoxClockCorrectionHours->addItems(items);
    ui->comboBoxClockCorrectionHours->setCurrentIndex(0);
}


void clockConfig::setMinutesRange(QStringList items)
{
    ui->comboBoxClockCorrectionMinutes->addItems(items);
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex(0);
}
