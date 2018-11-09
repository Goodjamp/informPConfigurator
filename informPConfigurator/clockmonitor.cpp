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

