﻿#include "QtLogin.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtLogin login_window;
    login_window.show();
    return a.exec();
}
