/********************************************************************************
** Form generated from reading UI file 'QtLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLOGIN_H
#define UI_QTLOGIN_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLogin
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userIDlineEdit;
    QLineEdit *userPasswordlineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLogin)
    {
        if (QtLogin->objectName().isEmpty())
            QtLogin->setObjectName(QStringLiteral("QtLogin"));
        QtLogin->resize(400, 300);
        centralWidget = new QWidget(QtLogin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 72, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 72, 21));
        userIDlineEdit = new QLineEdit(centralWidget);
        userIDlineEdit->setObjectName(QStringLiteral("userIDlineEdit"));
        userIDlineEdit->setGeometry(QRect(110, 40, 241, 21));
        userIDlineEdit->setMaxLength(9);
        userPasswordlineEdit = new QLineEdit(centralWidget);
        userPasswordlineEdit->setObjectName(QStringLiteral("userPasswordlineEdit"));
        userPasswordlineEdit->setGeometry(QRect(110, 90, 241, 21));
        userPasswordlineEdit->setMaxLength(16);
        userPasswordlineEdit->setFrame(false);
        userPasswordlineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 150, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 150, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 200, 93, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 200, 93, 28));
        QtLogin->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtLogin);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtLogin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtLogin);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtLogin->setStatusBar(statusBar);

        retranslateUi(QtLogin);

        QMetaObject::connectSlotsByName(QtLogin);
    } // setupUi

    void retranslateUi(QMainWindow *QtLogin)
    {
        QtLogin->setWindowTitle(QApplication::translate("QtLogin", "MainWindow", 0));
        label->setText(QApplication::translate("QtLogin", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\224\250\346\210\267ID:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("QtLogin", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\345\257\206\347\240\201:</span></p></body></html>", 0));
        userIDlineEdit->setPlaceholderText(QApplication::translate("QtLogin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267ID", 0));
        userPasswordlineEdit->setPlaceholderText(QApplication::translate("QtLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("QtLogin", "\346\263\250\345\206\214", 0));
        pushButton_2->setText(QApplication::translate("QtLogin", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        pushButton_3->setText(QApplication::translate("QtLogin", "\351\200\200\345\207\272", 0));
        pushButton_4->setText(QApplication::translate("QtLogin", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class QtLogin: public Ui_QtLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLOGIN_H
