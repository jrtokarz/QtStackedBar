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

    void setValues(const std::initializer_list<int>& list);

protected:
    void paintEvent(QPaintEvent* ev) override;

private:
    std::vector<int> m_values{};
};


#endif //QTSTACKEDBAR_QSTACKEDBAR_HPP
