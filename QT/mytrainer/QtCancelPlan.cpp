#include "QtCancelPlan.h"
#include "ui_QtCancelPlan.h"
#include "QtAdmin.h"
QtCancelPlan::QtCancelPlan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtCancelPlan)
{
    ui->setupUi(this);
}

QtCancelPlan::~QtCancelPlan()
{
    delete ui;
}

void QtCancelPlan::on_pushButton_clicked()//删除运行计划
{

}

void QtCancelPlan::on_pushButton_2_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
