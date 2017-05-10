#ifndef QtAddPlan_H
#define QtAddPlan_H

#include <QMainWindow>

namespace Ui {
class QtAddPlan;
}

class QtAddPlan : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtAddPlan(QWidget *parent = 0);
    ~QtAddPlan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtAddPlan *ui;
};

#endif // QtAddPlan_H
