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

    typedef enum {
        LCD_VALUE_DATE_1,
        LCD_VALUE_TIME_1,
        LCD_VALUE_DATE_2,
        LCD_VALUE_TIME_2,
        LCD_VALUE_DATE_3,
        LCD_VALUE_TIME_3,
        LCD_VALUE_DATE_4,
        LCD_VALUE_TIME_4,
        LCD_VALUE_FRQ,
        LCD_VALUE_TEMPERATURE,
        LCD_VALUE_HUMIDITY,
        LCD_VALUE_PRESSURE,
        LCD_VALUE_PRESSURE_GPA,
        LCD_VALUE_BUI,
    } lsdVal;

    void addLCD(QString name);
    void setChecked(uint8_t number, bool check);
    bool getChecked(uint8_t number);
    void enableControl(bool chekAble,lsdVal value);

private:
    QVector<QCheckBox*> listOfCheckbox;
    Ui::lcdStr *ui;
};

#endif // LCSDTR_H
