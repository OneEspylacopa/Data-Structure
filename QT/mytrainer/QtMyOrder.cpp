#include "QtMyOrder.h"
#include "ui_QtMyOrder.h"
#include "QtGeneralUser.h"
#include <QMessageBox>
#include "Transfer.hpp"

extern TrainSystem thomas;
extern User* identity;


QtMyOrder::QtMyOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtMyOrder)
{
    ui->setupUi(this);

    ui->datelineEdit->setReadOnly(true);
    ui->startlineEdit->setReadOnly(true);
    ui->terminuslineEdit->setReadOnly(true);
    ui->trainNumberlineEdit->setReadOnly(true);
    ui->ticketTypelineEdit->setReadOnly(true);

    QValidator *validator = new QIntValidator(0, 2000, this);
    ui->countlineEdit->setValidator(validator);

    row = -1;

    G = identity->GetOrders();

    QStringList header;

    header << "车次" << "起始站" << "终点站" << "日期" << "时间" << "票型" << "数量";

    ui->tableWidget->setRowCount(G.size());
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    for (int i = 0; i < (int)G.size(); i++) {
        QString cur[7];
        cur[0] = QString::fromStdString(G[i].trainNumber);
        cur[1] = Transfer::gbk2UTF(G[i].start);
        cur[2] = Transfer::gbk2UTF(G[i].end);
        cur[3] = QString::fromStdString(G[i].date.GetDate());
        cur[4] = QString::fromStdString(G[i].time.GetTime());
        cur[5] = Transfer::gbk2UTF(GetSeatType(G[i].type));
        cur[6] = QString::number(G[i].count);

        for (int j = 0; j < 7; j++) {
            QTableWidgetItem *item = new QTableWidgetItem(cur[j]);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

QtMyOrder::~QtMyOrder()
{
    delete ui;
}

void QtMyOrder::on_pushButton_clicked() // 退票
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
        SeatType seattype = GetSeatType(ui->ticketTypelineEdit->text().toLocal8Bit().toStdString());
        TicketInfo cur(G[row].trainNumber,
                       G[row].start,
                       G[row].end,
                       G[row].date,
                       G[row].time,
                       seattype,
                       G[row].price,
                       cnt);

        if (cnt == 0) {
            QMessageBox::warning(this, tr("警告!"),
                                 tr("数量不能为0!"),
                                 QMessageBox::Yes);
        } else
        if (identity->ReturnTicket(cur) == true) {
            QMessageBox::information(this, tr("信息"),
                                 tr("退票成功!"),
                                 QMessageBox::Yes);

            G = identity->GetOrders();

            QStringList header;

            header << "车次" << "起始站" << "终点站" << "日期" << "时间" << "票型" << "数量";

            ui->tableWidget->setRowCount(G.size());
            ui->tableWidget->setColumnCount(7);
            ui->tableWidget->setHorizontalHeaderLabels(header);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

            for (int i = 0; i < (int)G.size(); i++) {
                QString cur[7];
                cur[0] = QString::fromStdString(G[i].trainNumber);
                cur[1] = Transfer::gbk2UTF(G[i].start);
                cur[2] = Transfer::gbk2UTF(G[i].end);
                cur[3] = QString::fromStdString(G[i].date.GetDate());
                cur[4] = QString::fromStdString(G[i].time.GetTime());
                cur[5] = Transfer::gbk2UTF(GetSeatType(G[i].type));
                cur[6] = QString::number(G[i].count);

                for (int j = 0; j < 7; j++) {
                    QTableWidgetItem *item = new QTableWidgetItem(cur[j]);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    ui->tableWidget->setItem(i, j, item);
                }
            }
        } else {
            QMessageBox::warning(this, tr("警告!"),
                                 tr("退票失败!"),
                                 QMessageBox::Yes);
        }
        ui->countlineEdit->clear();
    }
}

void QtMyOrder::on_pushButton_2_clicked() //返回
{
    QtGeneralUser *general_user = new QtGeneralUser;
    general_user->setAttribute(Qt::WA_DeleteOnClose);
    close();
    general_user->show();
}

void QtMyOrder::on_tableWidget_clicked(const QModelIndex &index)
{
    row = index.row();
    ui->datelineEdit->setText(QString::fromStdString(G[row].date.GetDate()));
    ui->startlineEdit->setText(Transfer::gbk2UTF(G[row].start));
    ui->terminuslineEdit->setText(Transfer::gbk2UTF(G[row].end));
    ui->trainNumberlineEdit->setText(QString::fromStdString(G[row].trainNumber));
    ui->ticketTypelineEdit->setText(Transfer::gbk2UTF(GetSeatType(G[row].type)));
    ui->countlineEdit->clear();
}
