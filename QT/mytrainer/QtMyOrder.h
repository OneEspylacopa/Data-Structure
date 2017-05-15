#ifndef QtMyOrder_H
#define QtMyOrder_H

#include <QMainWindow>
#include <string>
#include "TrainSystem.h"
#include "map.hpp"
#include "vector"

namespace Ui {
class QtMyOrder;
}

class QtMyOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtMyOrder(QWidget *parent = 0);
    ~QtMyOrder();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::QtMyOrder *ui;
    vector<TicketInfo> G;
    int row;
};

#endif // QtMyOrder_H
