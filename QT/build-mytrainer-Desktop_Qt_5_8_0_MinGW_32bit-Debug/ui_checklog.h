/********************************************************************************
** Form generated from reading UI file 'checklog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKLOG_H
#define UI_CHECKLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checklog
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QLabel *label_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *checklog)
    {
        if (checklog->objectName().isEmpty())
            checklog->setObjectName(QStringLiteral("checklog"));
        checklog->resize(800, 600);
        centralwidget = new QWidget(checklog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 230, 93, 28));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(310, 10, 481, 571));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 40, 141, 41));
        checklog->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(checklog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        checklog->setStatusBar(statusbar);

        retranslateUi(checklog);

        QMetaObject::connectSlotsByName(checklog);
    } // setupUi

    void retranslateUi(QMainWindow *checklog)
    {
        checklog->setWindowTitle(QApplication::translate("checklog", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("checklog", "\350\277\224\345\233\236", Q_NULLPTR));
        label_7->setText(QApplication::translate("checklog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\237\245\347\234\213\347\263\273\347\273\237\346\227\245\345\277\227</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class checklog: public Ui_checklog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKLOG_H
