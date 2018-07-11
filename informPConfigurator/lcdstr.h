#ifndef LCDSTR_H
#define LCDSTR_H

#include <QWidget>
#include <QCheckBox>
#include <QVector>

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
    QVector<QCheckBox*> listOfCheckbox;
private:
    Ui::lcdStr *ui;
};

#endif // LCSDTR_H
