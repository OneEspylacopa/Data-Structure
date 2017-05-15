#ifndef QtAdmin_H
#define QtAdmin_H
#include <QMainWindow>
#include "TrainSystem.h"
extern TrainSystem thomas;
namespace Ui {
class QtAdmin;
}

class QtAdmin: public QMainWindow
{
    Q_OBJECT

public:
    explicit QtAdmin(QWidget *parent = 0);
    ~QtAdmin();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtAdmin *ui;
};

#endif // QtAdmin_H
