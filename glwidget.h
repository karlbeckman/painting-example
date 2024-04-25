#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

class Helper;

class GLWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(Helper* helper, QWidget* parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Helper* m_helper;
    int m_elapsed;
};

#endif // GLWIDGET_H
