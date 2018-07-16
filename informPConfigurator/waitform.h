#ifndef WAITFORM_H
#define WAITFORM_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class waitForm;
}

class waitForm : public QDialog
{
    Q_OBJECT

public:
    explicit waitForm(QWidget *parent = 0);
    ~waitForm();

private:
    Ui::waitForm *ui;
};

#endif // WAITFORM_H
