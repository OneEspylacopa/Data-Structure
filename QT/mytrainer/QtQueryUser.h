#ifndef QtQueryUser_H
#define QtQueryUser_H

#include <QMainWindow>

namespace Ui {
class QtQueryUser;
}

class QtQueryUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtQueryUser(QWidget *parent = 0);
    ~QtQueryUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QtQueryUser *ui;
};

#endif // QtQueryUser_H
