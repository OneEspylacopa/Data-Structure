#include "QtModifyInformation.h"
#include "ui_QtModifyInformation.h"
#include "QtGeneralUser.h"
#include "QtLogin.h"

QtModifyInformation::QtModifyInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtModifyInformation)
{
    ui->setupUi(this);
}

QtModifyInformation::~QtModifyInformation()
{
    delete ui;
}

void QtModifyInformation::on_pushButton_clicked()//修改信息
{

}

void QtModifyInformation::on_pushButton_2_clicked()//返回
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}

void QtModifyInformation::on_pushButton_3_clicked()//退出登录
{
    close();
    QtLogin *login = new QtLogin;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}
