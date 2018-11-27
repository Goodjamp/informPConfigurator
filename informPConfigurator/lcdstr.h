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

    void addLCD(QString name);
    void setChecked(uint8_t number, bool check);
    bool getChecked(uint8_t number);
private:
    QVector<QCheckBox*> listOfCheckbox;
    Ui::lcdStr *ui;
};

#endif // LCSDTR_H
