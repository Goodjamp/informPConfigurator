#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <QWidget>
#include <QStringList>

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
    bool setHourseCorrection(uint16_t hour);
    uint8_t getDayLight(void);
    uint16_t getCorrection(void);

private:
    Ui::clockConfig *ui;
};

#endif // CLOCKCONFIG_H
