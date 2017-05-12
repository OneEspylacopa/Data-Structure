#ifndef QtBookTicket_H
#define QtBookTicket_H

#include <QMainWindow>

namespace Ui {
class QtBookTicket;
}

class QtBookTicket : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtBookTicket(QWidget *parent = 0);
    ~QtBookTicket();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtBookTicket *ui;
};

#endif // QtBookTicket_H
