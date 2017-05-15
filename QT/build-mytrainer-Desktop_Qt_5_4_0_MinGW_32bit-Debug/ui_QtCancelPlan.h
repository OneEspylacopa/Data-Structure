/********************************************************************************
** Form generated from reading UI file 'QtCancelPlan.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCANCELPLAN_H
#define UI_QTCANCELPLAN_H

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

class Ui_QtCancelPlan
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtCancelPlan)
    {
        if (QtCancelPlan->objectName().isEmpty())
            QtCancelPlan->setObjectName(QStringLiteral("QtCancelPlan"));
        QtCancelPlan->resize(400, 300);
        centralwidget = new QWidget(QtCancelPlan);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 90, 121, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(81, 30, 81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 90, 81, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 30, 121, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 190, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 190, 93, 28));
        QtCancelPlan->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtCancelPlan);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtCancelPlan->setStatusBar(statusbar);

        retranslateUi(QtCancelPlan);

        QMetaObject::connectSlotsByName(QtCancelPlan);
    } // setupUi

    void retranslateUi(QMainWindow *QtCancelPlan)
    {
        QtCancelPlan->setWindowTitle(QApplication::translate("QtCancelPlan", "MainWindow", 0));
        label->setText(QApplication::translate("QtCancelPlan", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("QtCancelPlan", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("QtCancelPlan", "\345\217\226\346\266\210", 0));
        pushButton->setText(QApplication::translate("QtCancelPlan", "\345\210\240\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class QtCancelPlan: public Ui_QtCancelPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCANCELPLAN_H
