#include "widget.h"
#include "helper.h"

#include <QTimer>
#include <QDebug>
#include <QPainter>

Widget::Widget(Helper* helper, QWidget *parent)
    : QWidget{parent}, m_helper{helper}
{
    m_elapsed = 0;
    setFixedSize(200, 200);
}

void Widget::animate() {
    int l_interval = qobject_cast<QTimer* >(sender())->interval();
    m_elapsed = (m_elapsed + l_interval) % 1000;

    update();
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_helper->paint(&painter, event, m_elapsed);
    painter.end();
}
