#include "QtBookTicket.h"
#include "ui_QtBookTicket.h"
#include "QtGeneralUser.h"

QtBookTicket::QtBookTicket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtBookTicket)
{
    ui->setupUi(this);
}

QtBookTicket::~QtBookTicket()
{
    delete ui;
}

void QtBookTicket::on_pushButton_2_clicked()//查询车次
{

}

void QtBookTicket::on_pushButton_clicked()//订票
{

}

void QtBookTicket::on_pushButton_3_clicked()//返回
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}
