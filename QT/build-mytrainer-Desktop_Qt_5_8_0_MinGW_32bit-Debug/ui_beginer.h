/********************************************************************************
** Form generated from reading UI file 'beginer.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEGINER_H
#define UI_BEGINER_H

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

class Ui_beginer
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *beginer)
    {
        if (beginer->objectName().isEmpty())
            beginer->setObjectName(QStringLiteral("beginer"));
        beginer->resize(400, 300);
        centralwidget = new QWidget(beginer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(79, 200, 93, 28));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(189, 40, 121, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(239, 200, 93, 28));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(189, 100, 121, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(89, 100, 81, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 40, 81, 31));
        beginer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(beginer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        beginer->setStatusBar(statusbar);

        retranslateUi(beginer);

        QMetaObject::connectSlotsByName(beginer);
    } // setupUi

    void retranslateUi(QMainWindow *beginer)
    {
        beginer->setWindowTitle(QApplication::translate("beginer", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("beginer", "\345\274\200\345\247\213\345\217\221\345\224\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("beginer", "\345\217\226\346\266\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("beginer", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("beginer", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class beginer: public Ui_beginer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEGINER_H
