#ifndef QtCancelPlan_H
#define QtCancelPlan_H

#include <QMainWindow>

namespace Ui {
class QtCancelPlan;
}

class QtCancelPlan : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtCancelPlan(QWidget *parent = 0);
    ~QtCancelPlan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QtCancelPlan *ui;
};

#endif // QtCancelPlan_H
