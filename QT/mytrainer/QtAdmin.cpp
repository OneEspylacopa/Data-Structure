#include "QtAdmin.h"
#include "ui_QtAdmin.h"
#include "QtAddPlan.h"
#include "QtCancelPlan.h"
#include "QtModifyPlan.h"
#include "QtStartSelling.h"
#include "QtStopSelling.h"
#include "QtQueryUser.h"
#include "QtSystemLog.h"
#include "QtLogin.h"

QtAdmin::QtAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtAdmin)
{
    ui->setupUi(this);
}

QtAdmin::~QtAdmin()
{
    delete ui;
}

void QtAdmin::on_pushButton_5_clicked()//添加运行计划
{
    close();
    QtAddPlan *login = new QtAddPlan ;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_clicked()//删除运行计划
{
    close();
    QtModifyPlan *login = new QtModifyPlan ;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_4_clicked()//修改运行计划
{
    close();
    QtModifyPlan *login = new QtModifyPlan ;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_7_clicked()//开始发售
{
    close();
    QtStartSelling *login = new QtStartSelling ;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_6_clicked()//停止发售
{
    close();
    QtStopSelling *login = new QtStopSelling ;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_8_clicked()//查询用户信息
{
    close();
    QtQueryUser *login = new QtQueryUser;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_2_clicked()//查询系统日志
{
    close();
    QtSystemLog *login = new QtSystemLog;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

void QtAdmin::on_pushButton_3_clicked()//退出登录
{
    close();
    QtLogin *login = new QtLogin;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}
