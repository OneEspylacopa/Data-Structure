#ifndef QtRegister_H
#define QtRegister_H

#include <QMainWindow>
#include "QtLogin.h"
#include "TrainSystem.h"
#include "User.h"

namespace Ui {
class QtRegister;
}

class QtRegister : public QMainWindow
{
    Q_OBJECT


public:

    explicit QtRegister(QWidget *parent = 0);
    ~QtRegister();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::QtRegister *ui;
};

#endif // QtRegister_H
