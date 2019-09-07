#include <iostream>

#include <Qt/QtCore>
#include <QtGui/QApplication>
#include "QStackedBar.hpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QStackedBar stackedBar;

    stackedBar.show();

    app.exec();
}