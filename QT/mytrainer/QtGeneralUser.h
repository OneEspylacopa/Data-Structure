#ifndef QtGeneralUser_H
#define QtGeneralUser_H

#include <QMainWindow>

namespace Ui {
class QtGeneralUser;
}

class QtGeneralUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtGeneralUser(QWidget *parent = 0);
    ~QtGeneralUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtGeneralUser *ui;
};

#endif // QtGeneralUser_H
