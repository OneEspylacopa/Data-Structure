#include "QtRegister.h"
#include "QtLogin.h"
#include "ui_QtRegister.h"

QtRegister::QtRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtRegister)
{
    ui->setupUi(this);
}

QtRegister::~QtRegister()
{
    delete ui;
}

void QtRegister::on_pushButton_2_clicked()
{
    close();
    QtLogin *login = new QtLogin;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}
