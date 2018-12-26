/********************************************************************************
** Form generated from reading UI file 'Bspline_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSPLINE_DIALOG_H
#define UI_BSPLINE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Bspline_Dialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *Bspline_Dialog)
    {
        if (Bspline_Dialog->objectName().isEmpty())
            Bspline_Dialog->setObjectName(QStringLiteral("Bspline_Dialog"));
        Bspline_Dialog->resize(606, 552);
        label = new QLabel(Bspline_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 512, 512));
        pushButton = new QPushButton(Bspline_Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 530, 61, 23));
        pushButton_2 = new QPushButton(Bspline_Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 530, 61, 23));
        pushButton_3 = new QPushButton(Bspline_Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 530, 75, 23));
        pushButton_4 = new QPushButton(Bspline_Dialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 530, 75, 23));
        pushButton_5 = new QPushButton(Bspline_Dialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 530, 75, 23));

        retranslateUi(Bspline_Dialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Bspline_Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Bspline_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Bspline_Dialog)
    {
        Bspline_Dialog->setWindowTitle(QApplication::translate("Bspline_Dialog", "Bspline_Dialog", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Bspline_Dialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Bspline_Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Bspline_Dialog", "\346\234\200\350\277\221\351\202\273\346\217\222\345\200\274", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Bspline_Dialog", "\345\217\214\347\272\277\346\200\247\346\217\222\345\200\274", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Bspline_Dialog", "\345\217\214\344\270\211\346\254\241\346\217\222\345\200\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Bspline_Dialog: public Ui_Bspline_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSPLINE_DIALOG_H
