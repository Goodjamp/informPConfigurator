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


uint16_t clockConfig::getCorrection(void)
{
    return static_cast<uint16_t>(ui->comboBoxClockCorrectionHours->currentIndex() * 60 + ((ui->comboBoxClockCorrectionMinutes->currentIndex() == 1) ? (30) : (0)));
}

uint8_t clockConfig::getDayLight(void)
{
    return ui->checkBoxClockSetDaylight->isChecked() ? (1) : (0);
}

void clockConfig::setDayLight(bool state)
{
    ui->checkBoxClockSetDaylight->setChecked(state);
}

bool clockConfig::setMinutesCorrection(uint16_t minutes)
{
    if((minutes != 0) && (minutes != 30))
    {
        return false;
    }
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex((minutes == 0) ? (0) : (1));
    return true;
}

bool clockConfig::setHourseCorrection(uint16_t hour)
{
    if(hour >= 12)
    {
        return false;
    }
    ui->comboBoxClockCorrectionHours->setCurrentIndex(hour);
    return true;
}
