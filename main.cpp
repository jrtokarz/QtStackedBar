#include <iostream>

#include <Qt/QtCore>
#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/QLayout>
#include "QStackedBar.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QStackedBar* stackedBar = new QStackedBar(nullptr, 4);
    QDialog* dialog = new QDialog();
    QVBoxLayout* layout = new QVBoxLayout();
    QTimer* timer = new QTimer();

    dialog->setLayout(layout);
    layout->addWidget(stackedBar);

    stackedBar->setValues({10, 20, 30, 40});
    stackedBar->setMaximumHeight(20);
    stackedBar->setMaximumWidth(500);

    stackedBar->setColor(0, QColor::fromRgb(255, 0, 0));
    stackedBar->setColor(1, QColor::fromRgb(0, 255, 0));
    stackedBar->setColor(2, QColor::fromRgb(0, 0, 255));
    stackedBar->setColor(3, QColor::fromRgb(255, 255, 0));

    dialog->setFixedSize(500, 100);
    dialog->show();

    return app.exec();
}