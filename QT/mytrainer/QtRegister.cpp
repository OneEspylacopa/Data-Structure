#include "QtRegister.h"
#include "QtLogin.h"
#include "ui_QtRegister.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector.hpp"
#include "utility.hpp"

using std::string;
extern TrainSystem thomas;

QtRegister::QtRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtRegister)
{
    ui->setupUi(this);
    ui->userIDlineEdit->setMaxLength(9);
    ui->userNameLineEdit->setMaxLength(16);
    ui->userPasswordlineEdit->setMaxLength(16);
    ui->userCheckPasswordLineEdit->setMaxLength(16);

    ui->userPasswordlineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    ui->userCheckPasswordLineEdit->setContextMenuPolicy(Qt::NoContextMenu);
}

QtRegister::~QtRegister()
{
    delete ui;
}

void QtRegister::on_pushButton_2_clicked() //取消->返回login
{
    close();
    QtLogin *login = new QtLogin;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtRegister::on_pushButton_clicked() //注册
{
    if (ui->userCheckPasswordLineEdit->text() !=
            ui->userPasswordlineEdit->text()) {
        QMessageBox::warning(this, tr("警告!"),
                             tr("请再次确认你的密码!"),
                             QMessageBox::Yes);
        ui->userPasswordlineEdit->clear();
        ui->userCheckPasswordLineEdit->clear();
    } else {
        string userName = ui->userNameLineEdit->text().toStdString();
        string userId = ui->userIDlineEdit->text().toStdString();
        string userPassword = ui->userPasswordlineEdit->text().toStdString();

        pair<User*, string> tmp = thomas.user.Register(userName, userId, userPassword, true);
        User *cur = tmp.first;
        if (cur == nullptr) {
            QMessageBox::warning(this, tr("警告!"),
                                 QString::fromStdString(tmp.second),
                                 QMessageBox::Yes);
            ui->userIDlineEdit->clear();
            ui->userNameLineEdit->clear();
            ui->userPasswordlineEdit->clear();
            ui->userCheckPasswordLineEdit->clear();
        } else {
            QMessageBox::information(this, tr("信息"),
                                 tr("注册成功!"),
                                 QMessageBox::Yes);

            close();
            QtLogin *login = new QtLogin;
            login->setAttribute(Qt::WA_DeleteOnClose);
            login->show();
        }
    }
}
