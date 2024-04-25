#ifndef HELPER_H
#define HELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Helper
{
public:
    Helper();

    void paint(QPainter* painter, QPaintEvent* event, int elapsed);

private:
    QBrush m_background;
    QBrush m_circleBrush;
    QFont m_textFont;
    QPen m_circlePen;
    QPen m_textPen;

};

#endif // HELPER_H
