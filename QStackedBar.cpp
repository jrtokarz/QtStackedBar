//
// Created by jrt on 9/7/19.
//

#include <QtGui/QPainter>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "QStackedBar.hpp"

QStackedBar::QStackedBar(unsigned int segments, QWidget *parent):
    QWidget(parent)
{
    setSegments(segments);
}

void QStackedBar::setSegments(unsigned int segments)
{
    m_segments.resize(segments);
    assert(m_segments.size() == segments);
}

void QStackedBar::setColor(const unsigned int segment, const QColor color)
{
    assert(segment < m_segments.size());

    m_segments[segment].colour = color;
}

void QStackedBar::setValues(const std::initializer_list<int> &list)
{
    assert(list.size() == m_segments.size());

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

void QStackedBar::mapToSegment(QObject* obj, unsigned int segment)
{
    m_objToSegment[obj] = segment;
}

void QStackedBar::setValue(const int value)
{
    auto segment = m_objToSegment.at(QObject::sender());

    if (value != m_segments[segment].value)
    {
        m_segments[segment].value = value;
        emit repaint();
    }
}

void QStackedBar::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);
    QWidget::paintEvent(ev);
    uint32_t xpos = 0;

    painter.setPen(Qt::NoPen);

    for (auto segment : m_segments)
    {
        painter.setBrush(QBrush(segment.colour));
        painter.drawRect(xpos, 0, segment.value, this->height());
        xpos += segment.value;
    }
}

