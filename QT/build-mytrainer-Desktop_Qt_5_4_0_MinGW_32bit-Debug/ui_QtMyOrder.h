/********************************************************************************
** Form generated from reading UI file 'QtMyOrder.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMYORDER_H
#define UI_QTMYORDER_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMyOrder
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *startlineEdit;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *trainNumberlineEdit;
    QLineEdit *countlineEdit;
    QLabel *label_3;
    QLineEdit *terminuslineEdit;
    QPushButton *pushButton;
    QLineEdit *datelineEdit;
    QTableWidget *tableWidget;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLineEdit *ticketTypelineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtMyOrder)
    {
        if (QtMyOrder->objectName().isEmpty())
            QtMyOrder->setObjectName(QStringLiteral("QtMyOrder"));
        QtMyOrder->resize(800, 600);
        centralwidget = new QWidget(QtMyOrder);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(41, 80, 81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 290, 81, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 420, 72, 41));
        startlineEdit = new QLineEdit(centralwidget);
        startlineEdit->setObjectName(QStringLiteral("startlineEdit"));
        startlineEdit->setGeometry(QRect(140, 150, 121, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(41, 360, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 145, 81, 41));
        trainNumberlineEdit = new QLineEdit(centralwidget);
        trainNumberlineEdit->setObjectName(QStringLiteral("trainNumberlineEdit"));
        trainNumberlineEdit->setGeometry(QRect(140, 290, 121, 31));
        countlineEdit = new QLineEdit(centralwidget);
        countlineEdit->setObjectName(QStringLiteral("countlineEdit"));
        countlineEdit->setGeometry(QRect(140, 360, 121, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 215, 72, 41));
        terminuslineEdit = new QLineEdit(centralwidget);
        terminuslineEdit->setObjectName(QStringLiteral("terminuslineEdit"));
        terminuslineEdit->setGeometry(QRect(140, 220, 121, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 480, 93, 28));
        datelineEdit = new QLineEdit(centralwidget);
        datelineEdit->setObjectName(QStringLiteral("datelineEdit"));
        datelineEdit->setGeometry(QRect(140, 80, 121, 31));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(310, 10, 481, 571));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 10, 141, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 480, 93, 28));
        ticketTypelineEdit = new QLineEdit(centralwidget);
        ticketTypelineEdit->setObjectName(QStringLiteral("ticketTypelineEdit"));
        ticketTypelineEdit->setGeometry(QRect(140, 430, 121, 31));
        QtMyOrder->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtMyOrder);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtMyOrder->setStatusBar(statusbar);

        retranslateUi(QtMyOrder);

        QMetaObject::connectSlotsByName(QtMyOrder);
    } // setupUi

    void retranslateUi(QMainWindow *QtMyOrder)
    {
        QtMyOrder->setWindowTitle(QApplication::translate("QtMyOrder", "MainWindow", 0));
        label->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\245\250\345\236\213:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\225\260\351\207\217:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\265\267\347\202\271:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\273\210\347\202\271:</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("QtMyOrder", "\351\200\200\347\245\250", 0));
        label_7->setText(QApplication::translate("QtMyOrder", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\210\221\347\232\204\350\256\242\345\215\225</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("QtMyOrder", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class QtMyOrder: public Ui_QtMyOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMYORDER_H
