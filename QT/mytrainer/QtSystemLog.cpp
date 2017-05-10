#include "QtSystemLog.h"
#include "ui_QtSystemLog.h"
#include "QtAdmin.h"
QtSystemLog::QtSystemLog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtSystemLog)
{
    ui->setupUi(this);
}

QtSystemLog::~QtSystemLog()
{
    delete ui;
}

void QtSystemLog::on_pushButton_2_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
