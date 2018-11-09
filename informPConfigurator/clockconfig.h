#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <QWidget>

namespace Ui {
class clockConfig;
}

class clockConfig : public QWidget
{
    Q_OBJECT

public:
    explicit clockConfig(QWidget *parent = nullptr);
    ~clockConfig();

private:
    Ui::clockConfig *ui;
};

#endif // CLOCKCONFIG_H
