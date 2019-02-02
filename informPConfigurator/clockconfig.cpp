#include "clockconfig.h"
#include "ui_clockconfig.h"

clockConfig::clockConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clockConfig)
{
    ui->setupUi(this);
    QStringList signList = {"+", "-"};
    ui->comboBoxClockCorrectionSign->addItems(signList);
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

int16_t clockConfig::getCorrection(void)
{
    int16_t correction = static_cast<uint16_t>(ui->comboBoxClockCorrectionHours->currentIndex() * 60 + ((ui->comboBoxClockCorrectionMinutes->currentIndex() == 1) ? (30) : (0)));
    return (ui->comboBoxClockCorrectionSign->currentText() == "-") ? (-correction) : (correction);
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

bool clockConfig::setHourseCorrection(int16_t hour)
{
    ui->comboBoxClockCorrectionHours->setCurrentIndex((hour < 0) ? (-1 * hour) : (hour));
    ui->comboBoxClockCorrectionSign->setCurrentIndex((hour < 0) ? (1) : (0));
    return true;
}
