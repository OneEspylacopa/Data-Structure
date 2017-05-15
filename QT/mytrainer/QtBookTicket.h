#ifndef QtBookTicket_H
#define QtBookTicket_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector"

namespace Ui {
class QtBookTicket;
}

class QtBookTicket : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtBookTicket(QWidget *parent = 0);
    ~QtBookTicket();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::QtBookTicket *ui;
    vector<TicketsInfo> G;
    int row;
};

#endif // QtBookTicket_H
