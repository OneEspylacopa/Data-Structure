#include "QtGeneralUser.h"
#include "ui_QtGeneralUser.h"
#include "QtBookTicket.h"
#include "QtMyOrder.h"
#include "QtModifyInformation.h"
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector.hpp"


QtGeneralUser::QtGeneralUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtGeneralUser)
{
    ui->setupUi(this);
}

QtGeneralUser::~QtGeneralUser()
{
    delete ui;
}

void QtGeneralUser::on_pushButton_clicked() //车票
{
    QtBookTicket *tickey_book = new QtBookTicket;
    tickey_book->setAttribute(Qt::WA_DeleteOnClose);
    close();
    tickey_book->show();
}

void QtGeneralUser::on_pushButton_2_clicked() //订单
{
    QtMyOrder *my_order = new QtMyOrder;
    my_order->setAttribute(Qt::WA_DeleteOnClose);
    close();
    my_order->show();
}

void QtGeneralUser::on_pushButton_3_clicked() //修改信息
{
    QtModifyInformation *my_info = new QtModifyInformation;
    my_info->setAttribute(Qt::WA_DeleteOnClose);
    close();
    my_info->show();
}
