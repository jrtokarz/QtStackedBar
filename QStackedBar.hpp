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

    QStackedBar(unsigned int segements, QWidget *parent = nullptr);

    void setSegments(unsigned int segments);

    void setColor(const unsigned int segment, const QColor color);

    void setMinimumValue(const int minVal);
    void setMaximumValue(const int maxVal);

    void setValues(const std::initializer_list<int>& list);

public slots:
    void setValue(const unsigned int segment, const int value);

signals:
    void valueChanged(const unsigned int segment, const int value);

protected:
    void paintEvent(QPaintEvent* ev) override;

private:
    QBrush m_brush{};
    std::vector<Segment> m_segments{};
};


#endif //QTSTACKEDBAR_QSTACKEDBAR_HPP
