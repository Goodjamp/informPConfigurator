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

private:
    Ui::clockMonitor *ui;
};

#endif // CLOCKMONITOR_H
