#ifndef QtRegister_H
#define QtRegister_H

#include <QMainWindow>
#include "QtLogin.h"
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

private:
   // MainWindow ww;
    Ui::QtRegister *ui;
};

#endif // QtRegister_H
