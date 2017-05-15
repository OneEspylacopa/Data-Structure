/********************************************************************************
** Form generated from reading UI file 'QtRegister.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTREGISTER_H
#define UI_QTREGISTER_H

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

class Ui_QtRegister
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *userIDlineEdit;
    QLineEdit *userPasswordlineEdit;
    QLineEdit *userCheckPasswordLineEdit;
    QLineEdit *userNameLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtRegister)
    {
        if (QtRegister->objectName().isEmpty())
            QtRegister->setObjectName(QStringLiteral("QtRegister"));
        QtRegister->resize(400, 300);
        centralwidget = new QWidget(QtRegister);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 72, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 72, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 81, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 80, 81, 21));
        userIDlineEdit = new QLineEdit(centralwidget);
        userIDlineEdit->setObjectName(QStringLiteral("userIDlineEdit"));
        userIDlineEdit->setGeometry(QRect(130, 40, 201, 21));
        userIDlineEdit->setMaxLength(9);
        userPasswordlineEdit = new QLineEdit(centralwidget);
        userPasswordlineEdit->setObjectName(QStringLiteral("userPasswordlineEdit"));
        userPasswordlineEdit->setGeometry(QRect(130, 120, 201, 21));
        userPasswordlineEdit->setMaxLength(16);
        userPasswordlineEdit->setEchoMode(QLineEdit::Password);
        userCheckPasswordLineEdit = new QLineEdit(centralwidget);
        userCheckPasswordLineEdit->setObjectName(QStringLiteral("userCheckPasswordLineEdit"));
        userCheckPasswordLineEdit->setGeometry(QRect(130, 160, 201, 21));
        userCheckPasswordLineEdit->setMaxLength(16);
        userCheckPasswordLineEdit->setEchoMode(QLineEdit::Password);
        userNameLineEdit = new QLineEdit(centralwidget);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));
        userNameLineEdit->setGeometry(QRect(130, 80, 201, 21));
        userNameLineEdit->setMaxLength(16);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 220, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 220, 93, 28));
        QtRegister->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtRegister);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtRegister->setStatusBar(statusbar);

        retranslateUi(QtRegister);

        QMetaObject::connectSlotsByName(QtRegister);
    } // setupUi

    void retranslateUi(QMainWindow *QtRegister)
    {
        QtRegister->setWindowTitle(QApplication::translate("QtRegister", "MainWindow", 0));
        label->setText(QApplication::translate("QtRegister", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\224\250\346\210\267ID:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("QtRegister", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\345\257\206\347\240\201:</span></p><p><br/></p></body></html>", 0));
        label_3->setText(QApplication::translate("QtRegister", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\241\256\350\256\244\345\257\206\347\240\201:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("QtRegister", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215:</span></p></body></html>", 0));
        userIDlineEdit->setPlaceholderText(QApplication::translate("QtRegister", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267ID(9\344\275\215)", 0));
        userPasswordlineEdit->setPlaceholderText(QApplication::translate("QtRegister", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201(6-16\344\275\215)", 0));
        userCheckPasswordLineEdit->setPlaceholderText(QApplication::translate("QtRegister", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        userNameLineEdit->setPlaceholderText(QApplication::translate("QtRegister", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215(5-16\344\275\215)", 0));
        pushButton->setText(QApplication::translate("QtRegister", "\346\263\250\345\206\214", 0));
        pushButton_2->setText(QApplication::translate("QtRegister", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class QtRegister: public Ui_QtRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTREGISTER_H
