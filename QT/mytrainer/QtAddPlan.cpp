#include "QtAddPlan.h"
#include "ui_QtAddPlan.h"
#include "QtAdmin.h"
#include "TrainSystem.h"

extern TrainSystem thomas;
User adminer(&(thomas));

QtAddPlan::QtAddPlan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtAddPlan)
{
    ui->setupUi(this);
}

QtAddPlan::~QtAddPlan()
{
    delete ui;
}

void QtAddPlan::on_pushButton_clicked()//添加行
{
    QString str1 = ui->lineEdit_1->text().trimmed();
    QString str2 = ui->lineEdit_2->text().trimmed();
    QString str3 = ui->lineEdit_3->text().trimmed();
    QString str4 = ui->lineEdit_4->text().trimmed();
    QString str5 = ui->lineEdit_5->text().trimmed();
    QString str6 = ui->lineEdit_6->text().trimmed();
    QString str7 = ui->lineEdit_7->text().trimmed();
    QString str8 = ui->lineEdit_8->text().trimmed();
    QString str9 = ui->comboBox_6->currentText();
    QString str10 = ui->comboBox_7->currentText();
    QString str11 = ui->comboBox_8->currentText();
    QString str12 = ui->lineEdit_9->text().trimmed();
    QString str13 = ui->lineEdit_10->text().trimmed();
    QString str14 = ui->lineEdit_11->text().trimmed();
    QString str = str1 + ' ' + str2+ ' ' +str3+ ' ' +str4+ ' ' +str5+ ' ' +str9 + ' '+ str12+' '+ str6 +' '+str10 + ' '+str13+' '+str7+' '+str11+' '+str14+' '+str8;
    ui->listWidget->addItem(str);
}

void QtAddPlan::on_pushButton_3_clicked()//返回
{
    QtAdmin *admin = new QtAdmin;
    admin->setAttribute(Qt::WA_DeleteOnClose);
    close();
    admin->show();
}
int toint(std::string qstr)
{
    if (qstr == "一等座") return 0;
    if (qstr == "二等座") return 1;
    if (qstr == "无座")return 2;
    if (qstr == "商务座") return 3;
    if (qstr == "硬座") return  4;
    if (qstr == "软座") return 5;
    if (qstr == "硬卧上") return 6;
    if (qstr == "硬卧中") return  7;
    if (qstr == "硬卧下") return 8;
    if (qstr == "软卧下") return 9;
    if (qstr == "高级软卧")return 10;
    if (qstr == "特等座")return 11;
}

void QtAddPlan::on_pushButton_4_clicked()//上传新的运行计划
{

    int nCount = ui->listWidget->count();
    QString q_date = ui->lineEdit_date->text();
    QString q_number = ui->lineEdit_number->text();
    Date date;
    date.SetDate(q_date.toStdString());
    TrainNumber trainum(q_number.toStdString());
    for(int i=0; i<nCount; i++)
    {
        Station sta;
        QString strCurAll = ui->listWidget->item(i)->text();
        QString qstr = "";
        SeatType seat;
        std::string qnumber = "";
        int j = 0;
        int k = 0;
        for (j = 0;j < strCurAll.size();++j)
            if (strCurAll[j] != ' ') qstr += strCurAll[j];
        else
            {
                if (k == 0) sta.name = qstr.toStdString();
                if (k == 2) sta.arriveTime.SetTime(qstr.toStdString());
                if (k == 3) sta.stopTime.SetTime(qstr.toStdString());
                if (k == 4) sta.mileage = qstr.toInt();

                if (k == 5) qnumber = qstr.toStdString();
                if (k == 6) sta.seatCount[toint(qnumber) ] = qstr.toInt();
                if (k == 7) sta.price[toint(qnumber) ] = qstr.toDouble();

                if (k == 8) qnumber = qstr.toStdString();
                if (k == 9) sta.seatCount[toint(qnumber) ] = qstr.toInt();
                if (k == 10) sta.price[toint(qnumber) ] = qstr.toDouble();

                if (k == 11) qnumber  = qstr.toStdString();
                if (k == 12) sta.seatCount[toint(qnumber) ] = qstr.toInt();
                if (k == 13) sta.price[toint(qnumber) ] = qstr.toDouble();
                ++k;
                qstr = "";
            }
        trainum.AddStation(sta);
    }
    adminer.AddPlan(date,trainum);
}

void QtAddPlan::on_pushButton_2_clicked()//删除行
{
    int nCurIndex = ui->listWidget->currentRow();
    if(nCurIndex < 0)
    {
        return;
    }
    else
    {
        ui->listWidget->takeItem( nCurIndex );
    }
}

void QtAddPlan::on_listWidget_currentRowChanged(int currentRow)
{

}
