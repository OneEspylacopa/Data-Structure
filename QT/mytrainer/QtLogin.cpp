#include "QtLogin.h"
#include "QtRegister.h"
#include "ui_QtLogin.h"
#include "QtGeneralUser.h"
#include "QtAdmin.h"

QtLogin::QtLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtLogin)
{
    ui->setupUi(this);
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
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}

void QtLogin::on_pushButton_4_clicked()//管理员
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
