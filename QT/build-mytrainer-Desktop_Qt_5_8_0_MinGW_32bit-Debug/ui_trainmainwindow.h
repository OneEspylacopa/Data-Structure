/********************************************************************************
** Form generated from reading UI file 'trainmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINMAINWINDOW_H
#define UI_TRAINMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainmainwindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trainmainwindow)
    {
        if (trainmainwindow->objectName().isEmpty())
            trainmainwindow->setObjectName(QStringLiteral("trainmainwindow"));
        trainmainwindow->resize(450, 300);
        centralwidget = new QWidget(trainmainwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 93, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 150, 93, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 150, 93, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 40, 361, 41));
        trainmainwindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(trainmainwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trainmainwindow->setStatusBar(statusbar);

        retranslateUi(trainmainwindow);

        QMetaObject::connectSlotsByName(trainmainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *trainmainwindow)
    {
        trainmainwindow->setWindowTitle(QApplication::translate("trainmainwindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("trainmainwindow", "\350\275\246\347\245\250\351\242\204\350\256\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("trainmainwindow", "\350\256\242\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("trainmainwindow", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("trainmainwindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\254\242\350\277\216\344\275\277\347\224\250\346\211\230\351\251\254\346\226\257\347\201\253\350\275\246\347\245\250\347\263\273\347\273\237\357\274\201\357\274\201\357\274\201</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trainmainwindow: public Ui_trainmainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINMAINWINDOW_H
