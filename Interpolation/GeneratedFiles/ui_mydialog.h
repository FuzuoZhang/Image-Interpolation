/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QSlider *horizontalSlider_2;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QSlider *horizontalSlider_3;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QSpinBox *SpinBox_3;

    void setupUi(QDialog *mydialog)
    {
        if (mydialog->objectName().isEmpty())
            mydialog->setObjectName(QStringLiteral("mydialog"));
        mydialog->resize(327, 311);
        pushButton_4 = new QPushButton(mydialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 250, 51, 23));
        pushButton_3 = new QPushButton(mydialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 200, 75, 23));
        doubleSpinBox = new QDoubleSpinBox(mydialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(80, 110, 62, 22));
        label_6 = new QLabel(mydialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 70, 41, 20));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Caslon Pro"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        doubleSpinBox_2 = new QDoubleSpinBox(mydialog);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(80, 70, 62, 22));
        horizontalSlider_2 = new QSlider(mydialog);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(150, 70, 61, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(mydialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 110, 21, 20));
        label_4->setFont(font);
        horizontalSlider = new QSlider(mydialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 110, 61, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(mydialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 140, 75, 23));
        horizontalSlider_3 = new QSlider(mydialog);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(150, 30, 61, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(mydialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 30, 21, 20));
        label_5->setFont(font);
        pushButton_2 = new QPushButton(mydialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 170, 75, 23));
        pushButton_5 = new QPushButton(mydialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 250, 51, 23));
        SpinBox_3 = new QSpinBox(mydialog);
        SpinBox_3->setObjectName(QStringLiteral("SpinBox_3"));
        SpinBox_3->setGeometry(QRect(81, 30, 61, 22));

        retranslateUi(mydialog);
        QObject::connect(pushButton_4, SIGNAL(clicked()), mydialog, SLOT(close()));

        QMetaObject::connectSlotsByName(mydialog);
    } // setupUi

    void retranslateUi(QDialog *mydialog)
    {
        mydialog->setWindowTitle(QApplication::translate("mydialog", "mydialog", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("mydialog", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("mydialog", "\345\217\214\344\270\211\346\254\241\346\217\222\345\200\274", Q_NULLPTR));
        label_6->setText(QApplication::translate("mydialog", "\316\270(\342\210\205)", Q_NULLPTR));
        label_4->setText(QApplication::translate("mydialog", "\317\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mydialog", "\346\234\200\350\277\221\351\202\273\346\217\222\345\200\274", Q_NULLPTR));
        label_5->setText(QApplication::translate("mydialog", "R", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mydialog", "\345\217\214\347\272\277\346\200\247\346\217\222\345\200\274", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("mydialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
