#include "glwidget.h"
#include "helper.h"

#include <QTimer>
#include <QDebug>
#include <QPainter>

GLWidget::GLWidget(Helper* helper, QWidget* parent)
    : QOpenGLWidget{parent}, m_helper{helper}
{
    m_elapsed = 0;
    setFixedSize(200, 200);
    setAutoFillBackground(false);
}

void GLWidget::animate() {
    int l_interval = qobject_cast<QTimer* >(sender())->interval();
    m_elapsed = (m_elapsed + l_interval) % 1000;

    update();
}

void GLWidget::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_helper->paint(&painter, event, m_elapsed);
    painter.end();
}
