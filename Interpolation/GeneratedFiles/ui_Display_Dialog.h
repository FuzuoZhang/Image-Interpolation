/********************************************************************************
** Form generated from reading UI file 'Display_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_DIALOG_H
#define UI_DISPLAY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Display_Dialog
{
public:
    QLabel *mylabel;
    QPushButton *pushButton;

    void setupUi(QDialog *Display_Dialog)
    {
        if (Display_Dialog->objectName().isEmpty())
            Display_Dialog->setObjectName(QStringLiteral("Display_Dialog"));
        Display_Dialog->resize(629, 554);
        mylabel = new QLabel(Display_Dialog);
        mylabel->setObjectName(QStringLiteral("mylabel"));
        mylabel->setGeometry(QRect(40, 0, 512, 512));
        pushButton = new QPushButton(Display_Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 530, 75, 23));

        retranslateUi(Display_Dialog);

        QMetaObject::connectSlotsByName(Display_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Display_Dialog)
    {
        Display_Dialog->setWindowTitle(QApplication::translate("Display_Dialog", "Display_Dialog", Q_NULLPTR));
        mylabel->setText(QString());
        pushButton->setText(QApplication::translate("Display_Dialog", "\347\202\271\346\210\221\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Display_Dialog: public Ui_Display_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_DIALOG_H
