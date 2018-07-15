#include "waitform.h"
#include "ui_waitform.h"

waitForm::waitForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::waitForm)
{
    //ui->setupUi(this);
    //this->statusBar()->hide();//setSizeGripEnabled(false);// QStatusBar::setSizeGripEnabled(bool)
    QSize waitSize;
    waitSize.setHeight(100);
    waitSize.setWidth(200);
    this->setFixedSize(waitSize);
    //setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);

}

waitForm::~waitForm()
{
    delete ui;
}
