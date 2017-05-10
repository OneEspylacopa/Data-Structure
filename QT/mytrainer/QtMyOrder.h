#ifndef QtMyOrder_H
#define QtMyOrder_H

#include <QMainWindow>

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

private:
    Ui::QtMyOrder *ui;
};

#endif // QtMyOrder_H
