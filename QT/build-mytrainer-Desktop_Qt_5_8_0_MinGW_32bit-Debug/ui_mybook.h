/********************************************************************************
** Form generated from reading UI file 'mybook.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBOOK_H
#define UI_MYBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mybook
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mybook)
    {
        if (mybook->objectName().isEmpty())
            mybook->setObjectName(QStringLiteral("mybook"));
        mybook->resize(800, 600);
        centralwidget = new QWidget(mybook);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(41, 80, 81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 290, 81, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 410, 72, 41));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 150, 121, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(41, 350, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 145, 81, 41));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 290, 121, 31));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(140, 350, 121, 31));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 410, 121, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 215, 72, 41));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 220, 121, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 480, 93, 28));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 80, 121, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(310, 10, 481, 571));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 10, 141, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 480, 93, 28));
        mybook->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(mybook);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mybook->setStatusBar(statusbar);

        retranslateUi(mybook);

        QMetaObject::connectSlotsByName(mybook);
    } // setupUi

    void retranslateUi(QMainWindow *mybook)
    {
        mybook->setWindowTitle(QApplication::translate("mybook", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\227\245\346\234\237:</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\346\254\241:</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\245\250\345\236\213:</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\225\260\351\207\217:</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\265\267\347\202\271:</span></p></body></html>", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("mybook", "\344\270\200\347\255\211\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\344\272\214\347\255\211\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\346\227\240\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\345\225\206\345\212\241\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\347\241\254\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\350\275\257\345\272\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\347\241\254\345\215\247\344\270\212", Q_NULLPTR)
         << QApplication::translate("mybook", "\347\241\254\345\215\247\344\270\255", Q_NULLPTR)
         << QApplication::translate("mybook", "\347\241\254\345\215\247\344\270\213", Q_NULLPTR)
         << QApplication::translate("mybook", "\350\275\257\345\215\247\344\270\213", Q_NULLPTR)
         << QApplication::translate("mybook", "\351\253\230\347\272\247\350\275\257\345\215\247", Q_NULLPTR)
         << QApplication::translate("mybook", "\347\211\271\347\255\211\345\272\247", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\273\210\347\202\271:</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mybook", "\351\200\200\347\245\250", Q_NULLPTR));
        label_7->setText(QApplication::translate("mybook", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\210\221\347\232\204\350\256\242\345\215\225</span></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mybook", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mybook: public Ui_mybook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBOOK_H
