#include "clockmonitor.h"
#include "ui_clockmonitor.h"
#include "QString"

clockMonitor::clockMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clockMonitor)
{
    ui->setupUi(this);
}

clockMonitor::~clockMonitor()
{
    delete ui;
}


void clockMonitor::setClockName(QString clockName)
{
    ui->labelClockName->setText(clockName);
}



void clockMonitor::setYear(uint16_t year)
{
    ui->lineEditClockRezYear->setText(QString::number(year));
}

void clockMonitor::setMonth(uint16_t month)
{
    ui->lineEditClockRezMonth->setText(QString::number(month));
}

void clockMonitor::setDate(uint16_t date)
{
    ui->lineEditClockRezDay->setText(QString::number(date));
}

void clockMonitor::setHour(uint16_t hour)
{
    ui->lineEditClockRezHour->setText(QString::number(hour));
}

void clockMonitor::setMinutes(uint16_t minutes)
{
    ui->lineEditClockRezMinutes->setText(QString::number(minutes));
}

void clockMonitor::setSeconds(uint16_t seconds)
{
    ui->lineEditClockRezSecond->setText(QString::number(seconds));
}


uint16_t clockMonitor::getYear(void)
{
   bool rezConver;
   if (ui->lineEditClockRezYear->text() == NULL)
   {
       return 0;
   }
   return static_cast<uint16_t>(ui->lineEditClockRezYear->text().toUInt(&rezConver, 10));
}

uint16_t  clockMonitor::getMonth(void)
{
    bool rezConver;
    return static_cast<uint16_t>(ui->lineEditClockRezMonth->text().toUInt(&rezConver, 10));
}

uint16_t  clockMonitor::getDate(void)
{
    bool rezConver;
    return static_cast<uint16_t>(ui->lineEditClockRezDay->text().toUInt(&rezConver, 10));
}

uint16_t  clockMonitor::getHour(void)
{
    bool rezConver;
    return static_cast<uint16_t>(ui->lineEditClockRezHour->text().toUInt(&rezConver, 10));
}

uint16_t  clockMonitor::getMinutes(void)
{
    bool rezConver;
    return static_cast<uint16_t>(ui->lineEditClockRezMinutes->text().toUInt(&rezConver, 10));
}

uint16_t  clockMonitor::getSeconds(void)
{
    bool rezConver;
    return static_cast<uint16_t>(ui->lineEditClockRezSecond->text().toUInt(&rezConver, 10));
}
