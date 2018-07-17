#ifndef WAITFORM_H
#define WAITFORM_H

#include <QDialog>
#include <QTimer>
#include <QPushButton>

namespace Ui {
class waitForm;
}

class waitForm : public QWidget
{
    Q_OBJECT

public:
    explicit waitForm(QWidget *parent = 0);
    ~waitForm();

    void closeWaiteForm();

private:
    Ui::waitForm *ui;
};

#endif // WAITFORM_H
