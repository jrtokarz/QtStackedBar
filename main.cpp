#include <iostream>

#include <Qt/QtCore>
#include <QtGui/QApplication>
#include "QStackedBar.hpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QStackedBar stackedBar(4);

    stackedBar.setValues({10, 20, 30, 40});

    stackedBar.show();

    return app.exec();
}