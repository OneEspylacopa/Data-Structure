#include "QtModifyInformation.h"
#include "ui_QtModifyInformation.h"
#include "QtGeneralUser.h"
#include "QtLogin.h"
#include <QMessageBox>
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector.hpp"

#include <iostream>

using std::string;

extern User* identity;

QtModifyInformation::QtModifyInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtModifyInformation)
{
    ui->setupUi(this);
    ui->curIDlineEdit->setText(QString::fromStdString(identity->GetID()));
    ui->curNamelineEdit->setText(QString::fromStdString(identity->GetName()));
    ui->curIDlineEdit->setReadOnly(true);
    ui->curNamelineEdit->setReadOnly(true);
}

QtModifyInformation::~QtModifyInformation()
{
    delete ui;
}

void QtModifyInformation::on_pushButton_clicked()//修改信息
{

    if (ui->newCheckPasswordlineEdit->text() !=
            ui->newPasswordlineEdit->text()) {
        QMessageBox::warning(this, tr("警告!"),
                             tr("请再次确认你的密码!"),
                             QMessageBox::Yes);
        ui->newPasswordlineEdit->clear();
        ui->newCheckPasswordlineEdit->clear();
    } else {
        string userName = ui->newNamelineEdit->text().toStdString();
        string userPassword = ui->newPasswordlineEdit->text().toStdString();

        string tmp = identity->ModifyInfo(userName, userPassword);
        if (tmp == string()) {
            QMessageBox::information(this, tr("信息"),
                                 tr("修改成功!"),
                                 QMessageBox::Yes);

            ui->curIDlineEdit->setText(QString::fromStdString(identity->GetID()));
            ui->curNamelineEdit->setText(QString::fromStdString(identity->GetName()));
            ui->newPasswordlineEdit->clear();
            ui->newCheckPasswordlineEdit->clear();
            ui->newNamelineEdit->clear();
        } else {
            QMessageBox::warning(this, tr("警告!"),
                                 QString::fromStdString(tmp),
                                 QMessageBox::Yes);
        }
    }
}

void QtModifyInformation::on_pushButton_2_clicked()//返回
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}

void QtModifyInformation::on_pushButton_3_clicked()//退出登录
{
    identity = nullptr;
    close();
    QtLogin *login = new QtLogin;
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}
