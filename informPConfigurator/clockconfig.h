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

private:
    Ui::clockConfig *ui;
};

#endif // CLOCKCONFIG_H
