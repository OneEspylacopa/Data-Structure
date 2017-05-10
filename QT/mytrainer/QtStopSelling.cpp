#include "QtStopSelling.h"
#include "ui_QtStopSelling.h"
#include "QtAdmin.h"
QtStopSelling::QtStopSelling(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtStopSelling)
{
    ui->setupUi(this);
}

QtStopSelling::~QtStopSelling()
{
    delete ui;
}

void QtStopSelling::on_pushButton_clicked()//停止发售
{

}

void QtStopSelling::on_pushButton_2_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
