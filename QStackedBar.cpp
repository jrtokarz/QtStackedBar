//
// Created by jrt on 9/7/19.
//

#include <QtGui/QPainter>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "QStackedBar.hpp"

QStackedBar::QStackedBar(QWidget *parent, unsigned int segments):
    QWidget(parent)
{
    setSegments(segments);
}

void QStackedBar::setColor(const unsigned int segment, const QColor color)
{
    assert(segment < m_segmentCount);

    m_segments[segment-1].colour = color;
}

void QStackedBar::setValue(const unsigned int segment, const int value)
{
    assert(segment < m_segmentCount);

    m_segments[segment].value = value;
}

void QStackedBar::setValues(const std::initializer_list<int> &list)
{
    assert(list.size() == m_segmentCount);

    std::cout << "List size: " << list.size() << std::endl;

    auto list_iter = list.begin();
    auto segments_iter = m_segments.begin();

    while (list_iter != list.end())
    {
        (*segments_iter++).value = *list_iter++;
    }

    for (auto v : m_segments)
    {
        std::cout << v.value << std::endl;
    }
}

void QStackedBar::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);
    QWidget::paintEvent(ev);
    uint32_t xpos = 0;

    for (auto segment : m_segments)
    {
        auto color = QColor(segment.value, segment.value*2, segment.value*4);
        painter.setBrush(QBrush(color));
        painter.drawRect(xpos, 10, segment.value, 10);
        xpos += segment.value;
    }
}

