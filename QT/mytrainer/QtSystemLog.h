#ifndef QtSystemLog_H
#define QtSystemLog_H

#include <QMainWindow>

namespace Ui {
class QtSystemLog;
}

class QtSystemLog : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtSystemLog(QWidget *parent = 0);
    ~QtSystemLog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::QtSystemLog *ui;
};

#endif // QtSystemLog_H
