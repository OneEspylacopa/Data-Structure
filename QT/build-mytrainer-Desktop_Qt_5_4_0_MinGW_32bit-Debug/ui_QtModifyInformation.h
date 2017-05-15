/********************************************************************************
** Form generated from reading UI file 'QtModifyInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMODIFYINFORMATION_H
#define UI_QTMODIFYINFORMATION_H

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

class Ui_QtModifyInformation
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *curIDlineEdit;
    QLineEdit *curNamelineEdit;
    QLineEdit *newNamelineEdit;
    QLineEdit *newPasswordlineEdit;
    QLineEdit *newCheckPasswordlineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtModifyInformation)
    {
        if (QtModifyInformation->objectName().isEmpty())
            QtModifyInformation->setObjectName(QStringLiteral("QtModifyInformation"));
        QtModifyInformation->resize(800, 600);
        centralwidget = new QWidget(QtModifyInformation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 40, 101, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 110, 101, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(145, 200, 141, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 320, 111, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 260, 121, 41));
        curIDlineEdit = new QLineEdit(centralwidget);
        curIDlineEdit->setObjectName(QStringLiteral("curIDlineEdit"));
        curIDlineEdit->setGeometry(QRect(360, 50, 251, 31));
        curNamelineEdit = new QLineEdit(centralwidget);
        curNamelineEdit->setObjectName(QStringLiteral("curNamelineEdit"));
        curNamelineEdit->setGeometry(QRect(360, 110, 251, 31));
        newNamelineEdit = new QLineEdit(centralwidget);
        newNamelineEdit->setObjectName(QStringLiteral("newNamelineEdit"));
        newNamelineEdit->setGeometry(QRect(360, 210, 251, 31));
        newPasswordlineEdit = new QLineEdit(centralwidget);
        newPasswordlineEdit->setObjectName(QStringLiteral("newPasswordlineEdit"));
        newPasswordlineEdit->setGeometry(QRect(360, 270, 251, 31));
        newPasswordlineEdit->setEchoMode(QLineEdit::Password);
        newCheckPasswordlineEdit = new QLineEdit(centralwidget);
        newCheckPasswordlineEdit->setObjectName(QStringLiteral("newCheckPasswordlineEdit"));
        newCheckPasswordlineEdit->setGeometry(QRect(360, 330, 251, 31));
        newCheckPasswordlineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 420, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(355, 420, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 420, 93, 28));
        QtModifyInformation->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtModifyInformation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QtModifyInformation->setStatusBar(statusbar);

        retranslateUi(QtModifyInformation);

        QMetaObject::connectSlotsByName(QtModifyInformation);
    } // setupUi

    void retranslateUi(QMainWindow *QtModifyInformation)
    {
        QtModifyInformation->setWindowTitle(QApplication::translate("QtModifyInformation", "MainWindow", 0));
        label->setText(QApplication::translate("QtModifyInformation", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\224\250\346\210\267ID:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("QtModifyInformation", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("QtModifyInformation", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\226\260\347\232\204\347\224\250\346\210\267\345\220\215:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("QtModifyInformation", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\347\241\256\350\256\244\345\257\206\347\240\201:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("QtModifyInformation", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\226\260\347\232\204\345\257\206\347\240\201:</span></p></body></html>", 0));
        newNamelineEdit->setPlaceholderText(QApplication::translate("QtModifyInformation", "\350\257\267\350\276\223\345\205\245\346\226\260\347\224\250\346\210\267\345\220\215(5-18\344\275\215)", 0));
        newPasswordlineEdit->setPlaceholderText(QApplication::translate("QtModifyInformation", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201(6-18\344\275\215)", 0));
        newCheckPasswordlineEdit->setPlaceholderText(QApplication::translate("QtModifyInformation", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201(6-18\344\275\215)", 0));
        pushButton->setText(QApplication::translate("QtModifyInformation", "\344\277\256\346\224\271", 0));
        pushButton_2->setText(QApplication::translate("QtModifyInformation", "\350\277\224\345\233\236", 0));
        pushButton_3->setText(QApplication::translate("QtModifyInformation", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class QtModifyInformation: public Ui_QtModifyInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMODIFYINFORMATION_H
