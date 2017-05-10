#include "QtStartSelling.h"
#include "ui_QtStartSelling.h"
#include "QtAdmin.h"
QtStartSelling::QtStartSelling(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtStartSelling)
{
    ui->setupUi(this);
}

QtStartSelling::~QtStartSelling()
{
    delete ui;
}

void QtStartSelling::on_pushButton_clicked()//开始发售
{

}

void QtStartSelling::on_pushButton_2_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
