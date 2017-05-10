#ifndef QtStopSelling_H
#define QtStopSelling_H

#include <QMainWindow>

namespace Ui {
class QtStopSelling;
}

class QtStopSelling : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtStopSelling(QWidget *parent = 0);
    ~QtStopSelling();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QtStopSelling *ui;
};

#endif // QtStopSelling_H
