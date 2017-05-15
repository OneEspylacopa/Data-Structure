#include "QtBookTicket.h"
#include "ui_QtBookTicket.h"
#include "QtGeneralUser.h"
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector.hpp"
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QValidator>
#include <iostream>
#include "Transfer.hpp"

using std::string;

extern TrainSystem thomas;
extern User * identity;

QtBookTicket::QtBookTicket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtBookTicket)
{
    ui->setupUi(this);
    ui->trainNumberlineEdit->setReadOnly(true);
    QValidator *validator = new QIntValidator(0, 2000, this);
    ui->countlineEdit->setValidator(validator);
    row = -1;
}

QtBookTicket::~QtBookTicket()
{
    delete ui;
}

void QtBookTicket::on_pushButton_2_clicked()//查询车次
{
    if (ui->datelineEdit->text().isEmpty() || ui->startStationlineEdit->text().isEmpty() || ui->terminuslineEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("警告!"),
                             tr("查询关键字不能为空!"),
                             QMessageBox::Yes);
    } else {
        string date = ui->datelineEdit->text().toLocal8Bit().toStdString();
        string start = ui->startStationlineEdit->text().toLocal8Bit().toStdString();
        string terminus = ui->terminuslineEdit->text().toLocal8Bit().toStdString();

        G = identity->QueryTicket(Date(date), start, terminus);

        QStringList header;

        header << "车次" << "起始站" << "终点站" << "日期" << "时间";
        for (int i = 0; i < SEAT_TYPE_NUM; i++) {
            header << "作位类型" << "票价" << "余票";
        }

        ui->tableWidget->setRowCount(G.size());
        ui->tableWidget->setColumnCount(41);
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

        for (int i = 0; i < (int)G.size(); i++) {
            QString cur[41];
            cur[0] = QString::fromStdString(G[i].trainNumber);
            cur[1] = Transfer::gbk2UTF(G[i].start);
            cur[2] = Transfer::gbk2UTF(G[i].end);
            cur[3] = QString::fromStdString(G[i].date.GetDate());
            cur[4] = QString::fromStdString(G[i].time.GetTime());
            for (int j = 0; j < SEAT_TYPE_NUM; j++) {
                cur[5 + j * 3] = Transfer::gbk2UTF(GetSeatType((SeatType)j));
                cur[6 + j * 3] = QString::number(G[i].price[j]);
                cur[7 + j * 3] = QString::number(G[i].count[j]);
            }
            for (int j = 0; j < 41; j++) {
                QTableWidgetItem *item = new QTableWidgetItem(cur[j]);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->setItem(i, j, item);
            }
        }
    }
}

void QtBookTicket::on_pushButton_clicked()//订票
{
    string count = ui->countlineEdit->text().toStdString();
    if (row == -1) {
        QMessageBox::warning(this, tr("警告!"),
                             tr("请选择车票!"),
                             QMessageBox::Yes);
    } else {
        int cnt = 0;
        for (int i = 0; i < count.length(); i++)
            cnt = cnt * 10 + count[i] - '0';
        SeatType seattype = GetSeatType(ui->comboBox->currentText().toLocal8Bit().toStdString());
        TicketInfo cur(G[row].trainNumber,
                       G[row].start,
                       G[row].end,
                       G[row].date,
                       G[row].time,
                       seattype,
                       G[row].price[seattype],
                       cnt);
        if (cnt == 0) {
            QMessageBox::warning(this, tr("警告!"),
                                 tr("数量不能为0!"),
                                 QMessageBox::Yes);
        } else
        if (identity->BookTicket(cur) == true) {
            QMessageBox::information(this, tr("信息"),
                                 tr("购票成功!"),
                                 QMessageBox::Yes);

            if (ui->datelineEdit->text().isEmpty() || ui->startStationlineEdit->text().isEmpty() || ui->terminuslineEdit->text().isEmpty()) {
                QMessageBox::warning(this, tr("警告!"),
                                     tr("查询关键字不能为空!"),
                                     QMessageBox::Yes);
            } else {
                string date = ui->datelineEdit->text().toLocal8Bit().toStdString();
                string start = ui->startStationlineEdit->text().toLocal8Bit().toStdString();
                string terminus = ui->terminuslineEdit->text().toLocal8Bit().toStdString();

                G = identity->QueryTicket(Date(date), start, terminus);

                QStringList header;

                header << "车次" << "起始站" << "终点站" << "日期" << "时间";
                for (int i = 0; i < SEAT_TYPE_NUM; i++) {
                    header << "作位类型" << "票价" << "余票";
                }

                ui->tableWidget->setRowCount(G.size());
                ui->tableWidget->setColumnCount(41);
                ui->tableWidget->setHorizontalHeaderLabels(header);
                ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
                ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
                ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
                ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

                for (int i = 0; i < (int)G.size(); i++) {
                    QString cur[41];
                    cur[0] = QString::fromStdString(G[i].trainNumber);
                    cur[1] = Transfer::gbk2UTF(G[i].start);
                    cur[2] = Transfer::gbk2UTF(G[i].end);
                    cur[3] = QString::fromStdString(G[i].date.GetDate());
                    cur[4] = QString::fromStdString(G[i].time.GetTime());
                    for (int j = 0; j < SEAT_TYPE_NUM; j++) {
                        cur[5 + j * 3] = Transfer::gbk2UTF(GetSeatType((SeatType)j));
                        cur[6 + j * 3] = QString::number(G[i].price[j]);
                        cur[7 + j * 3] = QString::number(G[i].count[j]);
                    }
                    for (int j = 0; j < 41; j++) {
                        QTableWidgetItem *item = new QTableWidgetItem(cur[j]);
                        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                        ui->tableWidget->setItem(i, j, item);
                    }
                }
            }
        } else {
            QMessageBox::warning(this, tr("警告!"),
                                 tr("购票失败!"),
                                 QMessageBox::Yes);
        }
        ui->countlineEdit->clear();
    }
}

void QtBookTicket::on_pushButton_3_clicked()//返回
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}

void QtBookTicket::on_tableWidget_clicked(const QModelIndex &index)
{
    row = index.row();
    ui->trainNumberlineEdit->setText(QString::fromStdString(G[row].trainNumber));
    ui->countlineEdit->clear();
}
