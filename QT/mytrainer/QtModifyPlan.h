#ifndef QtModifyPlan_H
#define QtModifyPlan_H

#include <QMainWindow>

namespace Ui {
class QtModifyPlan;
}

class QtModifyPlan : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtModifyPlan(QWidget *parent = 0);
    ~QtModifyPlan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtModifyPlan *ui;
};

#endif // QtModifyPlan_H
