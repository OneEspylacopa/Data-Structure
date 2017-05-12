#include "QtAddPlan.h"
#include "ui_QtAddPlan.h"
#include "QtAdmin.h"

QtAddPlan::QtAddPlan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtAddPlan)
{
    ui->setupUi(this);
}

QtAddPlan::~QtAddPlan()
{
    delete ui;
}

void QtAddPlan::on_pushButton_clicked()//添加运行计划
{

}

void QtAddPlan::on_pushButton_3_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
