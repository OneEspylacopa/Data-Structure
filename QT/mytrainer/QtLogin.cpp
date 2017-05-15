#include "QtLogin.h"
#include "QtRegister.h"
#include "ui_QtLogin.h"
#include "QtGeneralUser.h"
#include "QtAdmin.h"
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector"
#include "SHA512.hpp"
#include <QMessageBox>
#include "utility.hpp"
#include <QString>

using std::string;

extern TrainSystem thomas;
extern User* identity;

QtLogin::QtLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtLogin)
{
    ui->setupUi(this);
    ui->userIDlineEdit->setMaxLength(9);
    ui->userPasswordlineEdit->setMaxLength(16);

    ui->userPasswordlineEdit->setContextMenuPolicy(Qt::NoContextMenu);
}

QtLogin::~QtLogin()
{
    delete ui;
}

void QtLogin::on_pushButton_clicked()//注册
{
    QtRegister *regist = new QtRegister;
    regist->setAttribute(Qt::WA_DeleteOnClose);
    close();
    regist->show();
}

void QtLogin::on_pushButton_3_clicked()//退出
{
    close();
}

void QtLogin::on_pushButton_2_clicked()//用户
{
    string userID = ui->userIDlineEdit->text().toStdString();
    string userPassword = ui->userPasswordlineEdit->text().toStdString();

    pair<User*, string> tmp = thomas.user.Login(userID, userPassword);
    User *cur = tmp.first;

    if (cur == nullptr) {
        QMessageBox::warning(this, tr("警告!"),
                             QString::fromStdString(tmp.second),
                             QMessageBox::Yes);

        ui->userPasswordlineEdit->clear();
        //ui->userIDlineEdit->clear();
    } else {
        identity = cur;
        QtGeneralUser *general_user = new QtGeneralUser;
        general_user->setAttribute(Qt::WA_DeleteOnClose);
        close();
        general_user->show();
    }
}

void QtLogin::on_pushButton_4_clicked()//管理员
{
    string userID = ui->userIDlineEdit->text().toStdString();
    string userPassword = ui->userPasswordlineEdit->text().toStdString();
    if (userID == "000000000" && userPassword == "000000000") {
        QtAdmin *admin = new QtAdmin;
        admin->setAttribute(Qt::WA_DeleteOnClose);
        close();
        admin->show();
    } else {
        QMessageBox::warning(this, tr("警告!"),
                             tr("账号或密码错误"),
                             QMessageBox::Yes);

        ui->userPasswordlineEdit->clear();
        //ui->userIDlineEdit->clear();
    }
}
