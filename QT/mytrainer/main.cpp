#include <QApplication>
#include <QMessageBox>
#include "QtLogin.h"
#include "TrainSystem.h"
#include "map.hpp"
#include "vector.hpp"
#include <iostream>

TrainSystem thomas;
User *identity;

class Execute {
public:
    Execute() {
        thomas.SetTrainData("TrainData");
        thomas.SetUserData("UserData");
        //thomas.Import();
        thomas.train.Import("traindata.txt");
    }
    ~Execute() {
        thomas.Export();
    }
}program;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    identity = nullptr;
    QtLogin login_window;
    login_window.show();

    return a.exec();
}
