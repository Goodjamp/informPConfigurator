#ifndef CLOCKMONITOR_H
#define CLOCKMONITOR_H

#include <QWidget>
#include <QString>

namespace Ui {
class clockMonitor;
}

class clockMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit clockMonitor(QWidget *parent = nullptr);
    ~clockMonitor();

    void setClockName(QString clockName);
    void setYear(uint16_t year);
    void setMonth(uint16_t month);
    void setDate(uint16_t date);
    void setHour(uint16_t hour);
    void setMinutes(uint16_t minutes);
    void setSeconds(uint16_t seconds);

    uint16_t getYear(void);
    uint16_t getMonth(void);
    uint16_t getDate(void);
    uint16_t getHour(void);
    uint16_t getMinutes(void);
    uint16_t getSeconds(void);

private:
    Ui::clockMonitor *ui;
};

#endif // CLOCKMONITOR_H
