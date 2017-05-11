#include "QtQueryUser.h"
#include "ui_QtQueryUser.h"
#include "QtAdmin.h"
QtQueryUser::QtQueryUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtQueryUser)
{
    ui->setupUi(this);
}

QtQueryUser::~QtQueryUser()
{
    delete ui;
}

void QtQueryUser::on_pushButton_clicked()//查询用户
{

}

void QtQueryUser::on_pushButton_2_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
