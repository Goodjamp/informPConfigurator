/********************************************************************************
** Form generated from reading UI file 'lcdstr.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LCDSTR_H
#define UI_LCDSTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lcdStr
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLCDName;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *checkBoxPar1;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxPar2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBoxPar3;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxPar4;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxPar5;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxPar6;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkBoxPar7;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBoxPar8;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBoxPar9;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *lcdStr)
    {
        if (lcdStr->objectName().isEmpty())
            lcdStr->setObjectName(QStringLiteral("lcdStr"));
        lcdStr->resize(828, 31);
        lcdStr->setMinimumSize(QSize(0, 20));
        lcdStr->setMaximumSize(QSize(16777215, 31));
        verticalLayout = new QVBoxLayout(lcdStr);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(lcdStr);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 10));
        line->setMaximumSize(QSize(16777215, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLCDName = new QLabel(lcdStr);
        labelLCDName->setObjectName(QStringLiteral("labelLCDName"));
        labelLCDName->setMinimumSize(QSize(20, 10));
        labelLCDName->setMaximumSize(QSize(80, 20));

        horizontalLayout->addWidget(labelLCDName);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        checkBoxPar1 = new QCheckBox(lcdStr);
        checkBoxPar1->setObjectName(QStringLiteral("checkBoxPar1"));
        checkBoxPar1->setMinimumSize(QSize(20, 20));
        checkBoxPar1->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBoxPar2 = new QCheckBox(lcdStr);
        checkBoxPar2->setObjectName(QStringLiteral("checkBoxPar2"));
        checkBoxPar2->setMinimumSize(QSize(20, 20));
        checkBoxPar2->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        checkBoxPar3 = new QCheckBox(lcdStr);
        checkBoxPar3->setObjectName(QStringLiteral("checkBoxPar3"));
        checkBoxPar3->setMinimumSize(QSize(20, 20));
        checkBoxPar3->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        checkBoxPar4 = new QCheckBox(lcdStr);
        checkBoxPar4->setObjectName(QStringLiteral("checkBoxPar4"));
        checkBoxPar4->setMinimumSize(QSize(20, 20));
        checkBoxPar4->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        checkBoxPar5 = new QCheckBox(lcdStr);
        checkBoxPar5->setObjectName(QStringLiteral("checkBoxPar5"));
        checkBoxPar5->setMinimumSize(QSize(20, 20));
        checkBoxPar5->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        checkBoxPar6 = new QCheckBox(lcdStr);
        checkBoxPar6->setObjectName(QStringLiteral("checkBoxPar6"));
        checkBoxPar6->setMinimumSize(QSize(20, 20));
        checkBoxPar6->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        checkBoxPar7 = new QCheckBox(lcdStr);
        checkBoxPar7->setObjectName(QStringLiteral("checkBoxPar7"));
        checkBoxPar7->setMinimumSize(QSize(20, 20));
        checkBoxPar7->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar7);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        checkBoxPar8 = new QCheckBox(lcdStr);
        checkBoxPar8->setObjectName(QStringLiteral("checkBoxPar8"));
        checkBoxPar8->setMinimumSize(QSize(20, 20));
        checkBoxPar8->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        checkBoxPar9 = new QCheckBox(lcdStr);
        checkBoxPar9->setObjectName(QStringLiteral("checkBoxPar9"));
        checkBoxPar9->setMinimumSize(QSize(20, 20));
        checkBoxPar9->setMaximumSize(QSize(2000, 20));

        horizontalLayout->addWidget(checkBoxPar9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(lcdStr);

        QMetaObject::connectSlotsByName(lcdStr);
    } // setupUi

    void retranslateUi(QWidget *lcdStr)
    {
        lcdStr->setWindowTitle(QApplication::translate("lcdStr", "Form", nullptr));
        labelLCDName->setText(QApplication::translate("lcdStr", "TextLabel", nullptr));
        checkBoxPar1->setText(QString());
        checkBoxPar2->setText(QString());
        checkBoxPar3->setText(QString());
        checkBoxPar4->setText(QString());
        checkBoxPar5->setText(QString());
        checkBoxPar6->setText(QString());
        checkBoxPar7->setText(QString());
        checkBoxPar8->setText(QString());
        checkBoxPar9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lcdStr: public Ui_lcdStr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LCDSTR_H
