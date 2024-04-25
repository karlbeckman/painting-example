#include "helper.h"

#include <QColor>
#include <QLinearGradient>
#include <QPointF>
#include <QPainter>
#include <QPaintEvent>

Helper::Helper() {
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    m_background = QBrush(QColor(64, 32, 64));
    m_circleBrush = QBrush(gradient);
    m_circlePen = QPen(Qt::black);
    m_circlePen.setWidth(1);
    m_textPen = QPen(Qt::white);
    m_textFont.setPixelSize(50);

}

void Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed) {
    painter->fillRect(event->rect(), m_background);
    painter->translate(100, 100);

    painter->save();
    painter->setBrush(m_circleBrush);
    painter->setPen(m_circlePen);
    painter->rotate(elapsed * 0.03);

    qreal r = elapsed / 1000.0;
    //r = 1;
    int n = 30;
    for (int i = 0; i < n; ++i) {
        painter->rotate(30);
        qreal factor = (i + r) / n;
        qreal radius = 0 + 120.0 * factor;
        qreal circleRadius = 1 + factor * 20;
        painter->drawEllipse(QRectF(radius, -circleRadius,
                                    circleRadius * 2, circleRadius * 2));
    }
    painter->restore();
    painter->setPen(m_textPen);
    painter->setFont(m_textFont);
    painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));

}
