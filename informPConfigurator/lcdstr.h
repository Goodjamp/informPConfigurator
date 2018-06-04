#ifndef LCDSTR_H
#define LCDSTR_H

#include <QWidget>

namespace Ui {
class lcdStr;
}

class lcdStr : public QWidget
{
    Q_OBJECT

public:
    explicit lcdStr(QWidget *parent = 0);
    ~lcdStr();

    void setNameLCD(QString newName);

private:
    Ui::lcdStr *ui;
};

#endif // LCSDTR_H
