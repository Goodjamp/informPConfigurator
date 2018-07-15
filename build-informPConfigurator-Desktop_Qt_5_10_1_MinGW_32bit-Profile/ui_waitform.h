/********************************************************************************
** Form generated from reading UI file 'waitform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITFORM_H
#define UI_WAITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waitForm
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *waitForm)
    {
        if (waitForm->objectName().isEmpty())
            waitForm->setObjectName(QStringLiteral("waitForm"));
        waitForm->resize(173, 101);
        centralwidget = new QWidget(waitForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("collor::red"));

        verticalLayout->addWidget(label);

        waitForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(waitForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 173, 21));
        waitForm->setMenuBar(menubar);
        statusbar = new QStatusBar(waitForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        waitForm->setStatusBar(statusbar);

        retranslateUi(waitForm);

        QMetaObject::connectSlotsByName(waitForm);
    } // setupUi

    void retranslateUi(QMainWindow *waitForm)
    {
        waitForm->setWindowTitle(QApplication::translate("waitForm", "MainWindow", nullptr));
        label->setText(QApplication::translate("waitForm", "\320\222\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202\321\201\321\217 \320\272\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waitForm: public Ui_waitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITFORM_H
