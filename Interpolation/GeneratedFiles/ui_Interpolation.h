/********************************************************************************
** Form generated from reading UI file 'Interpolation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERPOLATION_H
#define UI_INTERPOLATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterpolationClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterpolationClass)
    {
        if (InterpolationClass->objectName().isEmpty())
            InterpolationClass->setObjectName(QStringLiteral("InterpolationClass"));
        InterpolationClass->resize(400, 380);
        centralWidget = new QWidget(InterpolationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 70, 61, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(150, 100, 25, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 100, 111, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 70, 71, 16));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(275, 120, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(275, 160, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(275, 200, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 300, 75, 23));
        InterpolationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterpolationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        InterpolationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterpolationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InterpolationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterpolationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InterpolationClass->setStatusBar(statusBar);

        retranslateUi(InterpolationClass);
        QObject::connect(pushButton_5, SIGNAL(clicked()), InterpolationClass, SLOT(close()));

        QMetaObject::connectSlotsByName(InterpolationClass);
    } // setupUi

    void retranslateUi(QMainWindow *InterpolationClass)
    {
        InterpolationClass->setWindowTitle(QApplication::translate("InterpolationClass", "Interpolation", Q_NULLPTR));
        label->setText(QApplication::translate("InterpolationClass", "\350\257\267\351\200\211\346\213\251\345\233\276\347\211\207", Q_NULLPTR));
        pushButton->setText(QApplication::translate("InterpolationClass", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("InterpolationClass", "\350\257\267\351\200\211\346\213\251\345\217\230\346\215\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("InterpolationClass", "\346\227\213\350\275\254", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("InterpolationClass", "\346\260\264\346\263\242\347\272\271", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("InterpolationClass", "B\346\240\267\346\235\241\345\217\230\345\275\242", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("InterpolationClass", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InterpolationClass: public Ui_InterpolationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERPOLATION_H
