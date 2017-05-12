#ifndef QtLogin_H
#define QtLogin_H

#include <QMainWindow>
#include "QtRegister.h"
namespace Ui {
class QtLogin;
}

class QtLogin : public QMainWindow
{
    Q_OBJECT


public:
    explicit QtLogin(QWidget *parent = 0);
    ~QtLogin();

public slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:

    Ui::QtLogin *ui;
};

#endif // QtLogin_H
