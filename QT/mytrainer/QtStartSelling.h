#ifndef QtStartSelling_H
#define QtStartSelling_H

#include <QMainWindow>

namespace Ui {
class QtStartSelling;
}

class QtStartSelling : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtStartSelling(QWidget *parent = 0);
    ~QtStartSelling();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QtStartSelling *ui;
};

#endif // QtStartSelling_H
