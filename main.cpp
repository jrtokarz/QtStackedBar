#include <iostream>

#include <Qt/QtCore>
#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/QLayout>
#include <QtGui/QSlider>
#include "QStackedBar.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QStackedBar* stackedBar = new QStackedBar(4);
    QDialog* dialog = new QDialog();
    QVBoxLayout* layout = new QVBoxLayout();
    std::vector<QSlider*> sliders{};


    dialog->setLayout(layout);
    layout->addWidget(stackedBar);

    for (auto i=0; i<4; i++ )
    {
        sliders.push_back(new QSlider(Qt::Horizontal));
        stackedBar->mapToSegment(sliders[i], i);
        QObject::connect(sliders[i], SIGNAL(valueChanged(int)), stackedBar, SLOT(setValue(int)));
        layout->addWidget(sliders[i]);
		stackedBar->setValue(i, sliders[i]->value());
    }

    stackedBar->setMaximumHeight(20);
    stackedBar->setMaximumWidth(500);

    stackedBar->setColor(0, QColor::fromRgb(255, 0, 0));
    stackedBar->setColor(1, QColor::fromRgb(0, 255, 0));
    stackedBar->setColor(2, QColor::fromRgb(0, 0, 255));
    stackedBar->setColor(3, QColor::fromRgb(255, 255, 0));

    dialog->setFixedSize(500, 200);
    dialog->show();

    return app.exec();
}
