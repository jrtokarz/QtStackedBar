//
// Created by jrt on 9/7/19.
//

#ifndef QTSTACKEDBAR_QSTACKEDBAR_HPP
#define QTSTACKEDBAR_QSTACKEDBAR_HPP

#include <QtCore>
#include <QWidget>

#include <initializer_list>

class QStackedBar : public QWidget
{
    Q_OBJECT

public:
    struct Segment
    {
        int     value;
        QColor  colour;
    };

    QStackedBar(const unsigned int segments = 1);

    void addSegments(const unsigned int segments);

    void setColor(const unsigned int segment, const QColor color);

    void setMinimumValue(const int minVal);
    void setMaximumValue(const int maxVal);

    void setValue(const unsigned int segment, const int value);
    void setValues(const std::initializer_list<int>& list);

protected:
    void paintEvent(QPaintEvent* ev) override;

private:
    uint32_t    m_segmentCount{0};
    std::vector<Segment> m_segments{};
};


#endif //QTSTACKEDBAR_QSTACKEDBAR_HPP
