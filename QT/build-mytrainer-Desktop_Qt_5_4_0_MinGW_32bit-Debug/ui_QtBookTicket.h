/********************************************************************************
** Form generated from reading UI file 'QtBookTicket.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTBOOKTICKET_H
#define UI_QTBOOKTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtBookTicket
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *datelineEdit;
    QLineEdit *startStationlineEdit;
    QLineEdit *terminuslineEdit;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QLineEdit *trainNumberlineEdit;
    QLineEdit *countlineEdit;
    QPushButton *pushButton_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtBookTicket)
    {
        if (QtBookTicket->objectName().isEmpty())
            QtBookTicket->setObjectName(QStringLiteral("QtBookTicket"));
        QtBookTicket->resize(800, 600);
        centralwidget = new QWidget(QtBookTicket);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(31, 40, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 105, 81, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 175, 72, 41));
        datelineEdit = new QLineEdit(centralwidget);
        datelineEdit->setObjectName(QStringLiteral("datelineEdit"));
        datelineEdit->setGeometry(QRect(130, 40, 121, 31));
        startStationlineEdit = new QLineEdit(centralwidget);
        startStationlineEdit->setObjectName(QStringLiteral("startStationlineEdit"));
        startStationlineEdit->setGeometry(QRect(130, 110, 121, 31));
        terminuslineEdit = new QLineEdit(centralwidget);
        terminuslineEdit->setObjectName(QStringLiteral("terminuslineEdit"));
        terminuslineEdit->setGeometry(QRect(130, 180, 121, 31));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(300, 10, 481, 571));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 520, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 240, 93, 28));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(31, 330, 81, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(31, 390, 81, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 450, 72, 41));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 450, 121, 31));
        trainNumberlineEdit = new QLineEdit(centralwidget);
        trainNumberlineEdit->setObjectName(QStringLiteral("trainNumberlineEdit"));
        trainNumberlineEdit->setGeometry(QRect(130, 330, 121, 31));
        countlineEdit = new QLineEdit(centralwidget);
        countlineEdit->setObjectName(QStringLiteral("countlineEdit"));
        countlineEdit->setGeometry(QRect(130, 390, 121, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 520, 93, 28));
        QtBookTicket->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtBookTicket);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtBookTicket->setStatusBar(statusbar);

        retranslateUi(QtBookTicket);

        QMetaObject::connectSlotsByName(QtBookTicket);
    } // setupUi

    void retranslateUi(QMainWindow *QtBookTicket)
    {
        QtBookTicket->setWindowTitle(QApplication::translate("QtBookTicket", "MainWindow", 0));
        label->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\265\267\347\202\271:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\273\210\347\202\271:</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("QtBookTicket", "\350\256\242\347\245\250", 0));
        pushButton_2->setText(QApplication::translate("QtBookTicket", "\346\237\245\350\257\242", 0));
        label_4->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\225\260\351\207\217:</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("QtBookTicket", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\245\250\345\236\213:</span></p></body></html>", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QtBookTicket", "\344\270\200\347\255\211\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\344\272\214\347\255\211\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\346\227\240\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\345\225\206\345\212\241\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\347\241\254\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\350\275\257\345\272\247", 0)
         << QApplication::translate("QtBookTicket", "\347\241\254\345\215\247\344\270\212", 0)
         << QApplication::translate("QtBookTicket", "\347\241\254\345\215\247\344\270\255", 0)
         << QApplication::translate("QtBookTicket", "\347\241\254\345\215\247\344\270\213", 0)
         << QApplication::translate("QtBookTicket", "\350\275\257\345\215\247\344\270\213", 0)
         << QApplication::translate("QtBookTicket", "\351\253\230\347\272\247\350\275\257\345\215\247", 0)
         << QApplication::translate("QtBookTicket", "\347\211\271\347\255\211\345\272\247", 0)
        );
        pushButton_3->setText(QApplication::translate("QtBookTicket", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class QtBookTicket: public Ui_QtBookTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTBOOKTICKET_H
