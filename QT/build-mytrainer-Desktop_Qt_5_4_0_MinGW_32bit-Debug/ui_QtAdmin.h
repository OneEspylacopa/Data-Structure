/********************************************************************************
** Form generated from reading UI file 'QtAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTADMIN_H
#define UI_QTADMIN_H

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

class Ui_QtAdmin
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtAdmin)
    {
        if (QtAdmin->objectName().isEmpty())
            QtAdmin->setObjectName(QStringLiteral("QtAdmin"));
        QtAdmin->resize(400, 300);
        centralwidget = new QWidget(QtAdmin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(142, 40, 101, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(142, 210, 101, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(272, 210, 101, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(272, 40, 101, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(12, 40, 101, 28));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(272, 120, 101, 28));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(12, 120, 101, 28));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(12, 210, 101, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 110, 131, 41));
        QtAdmin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtAdmin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtAdmin->setStatusBar(statusbar);

        retranslateUi(QtAdmin);

        QMetaObject::connectSlotsByName(QtAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *QtAdmin)
    {
        QtAdmin->setWindowTitle(QApplication::translate("QtAdmin", "MainWindow", 0));
        pushButton->setText(QApplication::translate("QtAdmin", "\345\210\240\351\231\244\350\277\220\350\241\214\350\256\241\345\210\222", 0));
        pushButton_2->setText(QApplication::translate("QtAdmin", "\346\237\245\347\234\213\347\263\273\347\273\237\346\227\245\345\277\227", 0));
        pushButton_3->setText(QApplication::translate("QtAdmin", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        pushButton_4->setText(QApplication::translate("QtAdmin", "\344\277\256\346\224\271\350\277\220\350\241\214\350\256\241\345\210\222", 0));
        pushButton_5->setText(QApplication::translate("QtAdmin", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222", 0));
        pushButton_6->setText(QApplication::translate("QtAdmin", "\345\201\234\346\255\242\345\217\221\345\224\256", 0));
        pushButton_7->setText(QApplication::translate("QtAdmin", "\345\274\200\345\247\213\345\217\221\345\224\256", 0));
        pushButton_8->setText(QApplication::translate("QtAdmin", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("QtAdmin", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\220\221\347\256\241\347\220\206\345\221\230\344\275\216\345\244\264\357\274\201</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class QtAdmin: public Ui_QtAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTADMIN_H
