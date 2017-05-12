#include "QtModifyPlan.h"
#include "ui_QtModifyPlan.h"
#include "QtAdmin.h"
QtModifyPlan::QtModifyPlan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtModifyPlan)
{
    ui->setupUi(this);
}

QtModifyPlan::~QtModifyPlan()
{
    delete ui;
}

void QtModifyPlan::on_pushButton_clicked()//修改运行计划
{

}

void QtModifyPlan::on_pushButton_3_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
