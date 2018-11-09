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
