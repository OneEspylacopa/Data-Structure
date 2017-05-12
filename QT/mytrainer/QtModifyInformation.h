#ifndef QtModifyInformation_H
#define QtModifyInformation_H

#include <QMainWindow>

namespace Ui {
class QtModifyInformation;
}

class QtModifyInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtModifyInformation(QWidget *parent = 0);
    ~QtModifyInformation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::QtModifyInformation *ui;
};

#endif // QtModifyInformation_H
