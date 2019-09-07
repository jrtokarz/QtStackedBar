//
// Created by jrt on 9/7/19.
//

#ifndef QTSTACKEDBAR_QSTACKEDBAR_HPP
#define QTSTACKEDBAR_QSTACKEDBAR_HPP

#include <QtCore>

#include <initializer_list>

class QStackedBar : public QWidget
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent* ev) override;

    void setValues(const std::initializer_list<int>& list);

private:
    std::vector<int> m_values{};
};


#endif //QTSTACKEDBAR_QSTACKEDBAR_HPP
