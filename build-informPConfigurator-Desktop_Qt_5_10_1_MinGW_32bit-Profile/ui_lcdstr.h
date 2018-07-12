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
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *checkBoxPar1;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxPar2;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBoxPar3;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxPar4;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxPar5;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxPar6;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkBoxPar7;
    QFrame *line_9;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBoxPar8;
    QFrame *line_10;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBoxPar9;

    void setupUi(QWidget *lcdStr)
    {
        if (lcdStr->objectName().isEmpty())
            lcdStr->setObjectName(QStringLiteral("lcdStr"));
        lcdStr->resize(1346, 31);
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
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        labelLCDName = new QLabel(lcdStr);
        labelLCDName->setObjectName(QStringLiteral("labelLCDName"));
        labelLCDName->setMinimumSize(QSize(131, 20));
        labelLCDName->setMaximumSize(QSize(131, 20));

        horizontalLayout->addWidget(labelLCDName);

        line_5 = new QFrame(lcdStr);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        checkBoxPar1 = new QCheckBox(lcdStr);
        checkBoxPar1->setObjectName(QStringLiteral("checkBoxPar1"));
        checkBoxPar1->setMinimumSize(QSize(50, 20));
        checkBoxPar1->setMaximumSize(QSize(50, 20));
        checkBoxPar1->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar1);

        line_2 = new QFrame(lcdStr);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBoxPar2 = new QCheckBox(lcdStr);
        checkBoxPar2->setObjectName(QStringLiteral("checkBoxPar2"));
        checkBoxPar2->setMinimumSize(QSize(50, 20));
        checkBoxPar2->setMaximumSize(QSize(50, 20));
        checkBoxPar2->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar2);

        line_3 = new QFrame(lcdStr);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        checkBoxPar3 = new QCheckBox(lcdStr);
        checkBoxPar3->setObjectName(QStringLiteral("checkBoxPar3"));
        checkBoxPar3->setMinimumSize(QSize(50, 20));
        checkBoxPar3->setMaximumSize(QSize(50, 20));
        checkBoxPar3->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar3);

        line_4 = new QFrame(lcdStr);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        checkBoxPar4 = new QCheckBox(lcdStr);
        checkBoxPar4->setObjectName(QStringLiteral("checkBoxPar4"));
        checkBoxPar4->setMinimumSize(QSize(50, 20));
        checkBoxPar4->setMaximumSize(QSize(50, 20));
        checkBoxPar4->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar4);

        line_6 = new QFrame(lcdStr);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        checkBoxPar5 = new QCheckBox(lcdStr);
        checkBoxPar5->setObjectName(QStringLiteral("checkBoxPar5"));
        checkBoxPar5->setMinimumSize(QSize(50, 20));
        checkBoxPar5->setMaximumSize(QSize(50, 20));
        checkBoxPar5->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar5);

        line_7 = new QFrame(lcdStr);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        checkBoxPar6 = new QCheckBox(lcdStr);
        checkBoxPar6->setObjectName(QStringLiteral("checkBoxPar6"));
        checkBoxPar6->setMinimumSize(QSize(50, 20));
        checkBoxPar6->setMaximumSize(QSize(50, 20));
        checkBoxPar6->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar6);

        line_8 = new QFrame(lcdStr);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        checkBoxPar7 = new QCheckBox(lcdStr);
        checkBoxPar7->setObjectName(QStringLiteral("checkBoxPar7"));
        checkBoxPar7->setMinimumSize(QSize(50, 20));
        checkBoxPar7->setMaximumSize(QSize(50, 20));
        checkBoxPar7->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar7);

        line_9 = new QFrame(lcdStr);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_9);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        checkBoxPar8 = new QCheckBox(lcdStr);
        checkBoxPar8->setObjectName(QStringLiteral("checkBoxPar8"));
        checkBoxPar8->setMinimumSize(QSize(50, 20));
        checkBoxPar8->setMaximumSize(QSize(50, 20));
        checkBoxPar8->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar8);

        line_10 = new QFrame(lcdStr);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        checkBoxPar9 = new QCheckBox(lcdStr);
        checkBoxPar9->setObjectName(QStringLiteral("checkBoxPar9"));
        checkBoxPar9->setMinimumSize(QSize(50, 20));
        checkBoxPar9->setMaximumSize(QSize(50, 20));
        checkBoxPar9->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkBoxPar9);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(lcdStr);

        QMetaObject::connectSlotsByName(lcdStr);
    } // setupUi

    void retranslateUi(QWidget *lcdStr)
    {
        lcdStr->setWindowTitle(QApplication::translate("lcdStr", "Form", nullptr));
        labelLCDName->setText(QApplication::translate("lcdStr", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lcdStr: public Ui_lcdStr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LCDSTR_H
