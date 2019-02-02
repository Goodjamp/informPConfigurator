#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <QWidget>
#include <QStringList>
#include <QString>

namespace Ui {
class clockConfig;
}

class clockConfig : public QWidget
{
    Q_OBJECT

public:
    explicit clockConfig(QWidget *parent = nullptr);
    ~clockConfig();

    void setHorseRange(QStringList items);
    void setMinutesRange(QStringList items);
    void setDayLight(bool state);
    bool setMinutesCorrection(uint16_t minutes);
    bool setHourseCorrection(int16_t hour);
    uint8_t getDayLight(void);
    int16_t getCorrection(void);

private:
    Ui::clockConfig *ui;
};

#endif // CLOCKCONFIG_H
