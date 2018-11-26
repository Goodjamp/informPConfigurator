#include "clockmonitor.h"
#include "ui_clockmonitor.h"

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



void clockMonitor::setYear(uint16_t year){}
void clockMonitor::setMonth(uint16_t month){}
void clockMonitor::setDate(uint16_t date){}
void clockMonitor::setHour(uint16_t hour){}
void clockMonitor::setMinutes(uint16_t minutes){}
void clockMonitor::setSeconds(uint16_t seconds){}

uint16_t clockMonitor::getYear(void){}
uint16_t clockMonitor::getMonth(void){}
uint16_t clockMonitor::getDate(void){}
uint16_t clockMonitor::getHour(void){}
uint16_t clockMonitor::getMinutes(void){}
uint16_t clockMonitor::getSeconds(void){}
