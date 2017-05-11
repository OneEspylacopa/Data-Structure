#include "QtMyOrder.h"
#include "ui_QtMyOrder.h"
#include "QtGeneralUser.h"

QtMyOrder::QtMyOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtMyOrder)
{
    ui->setupUi(this);
}

QtMyOrder::~QtMyOrder()
{
    delete ui;
}

void QtMyOrder::on_pushButton_clicked()
{

}

void QtMyOrder::on_pushButton_2_clicked()
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}
