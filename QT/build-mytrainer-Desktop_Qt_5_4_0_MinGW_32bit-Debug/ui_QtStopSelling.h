/********************************************************************************
** Form generated from reading UI file 'QtStopSelling.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTOPSELLING_H
#define UI_QTSTOPSELLING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtStopSelling
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtStopSelling)
    {
        if (QtStopSelling->objectName().isEmpty())
            QtStopSelling->setObjectName(QStringLiteral("QtStopSelling"));
        QtStopSelling->resize(400, 300);
        centralwidget = new QWidget(QtStopSelling);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 100, 81, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 40, 121, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 200, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(71, 40, 81, 31));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 100, 121, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 200, 93, 28));
        QtStopSelling->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtStopSelling);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtStopSelling->setStatusBar(statusbar);

        retranslateUi(QtStopSelling);

        QMetaObject::connectSlotsByName(QtStopSelling);
    } // setupUi

    void retranslateUi(QMainWindow *QtStopSelling)
    {
        QtStopSelling->setWindowTitle(QApplication::translate("QtStopSelling", "MainWindow", 0));
        label_4->setText(QApplication::translate("QtStopSelling", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("QtStopSelling", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("QtStopSelling", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("QtStopSelling", "\345\201\234\346\255\242\345\217\221\345\224\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QtStopSelling: public Ui_QtStopSelling {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTOPSELLING_H
