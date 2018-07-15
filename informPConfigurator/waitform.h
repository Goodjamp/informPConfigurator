#ifndef WAITFORM_H
#define WAITFORM_H

#include <QMainWindow>

namespace Ui {
class waitForm;
}

class waitForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit waitForm(QWidget *parent = 0);
    ~waitForm();

private:
    Ui::waitForm *ui;
};

#endif // WAITFORM_H
