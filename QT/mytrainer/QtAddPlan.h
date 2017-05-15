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

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:

    Ui::QtAddPlan *ui;
};

#endif // QtAddPlan_H
