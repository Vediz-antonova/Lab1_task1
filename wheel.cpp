#include "wheel.h"
#include <QPainter>
#include <QKeyEvent>

Wheel::Wheel(QWidget *parent) : Circle(parent) {
    angle = 0.0;
    press = 0;

    setFocusPolicy(Qt::StrongFocus);
}

void Wheel::paintEvent(QPaintEvent *event){
    Circle::paintEvent(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    drawWheel(&painter);
}

void Wheel::rotate(){
    int step = 1;
    if(press){
        angle += step;
    } /*else {
        if (angle != 0){
            angle -= step;
        } else {
            angle = 0;
        }
    }*/

    update();
}

void Wheel::drawWheel(QPainter *painter){
    rotate();
    const int num = 8;
    const qreal length = r;

    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter->setPen(pen);

    for(int i = 0; i < num; ++i){
        qreal rad = 2 * M_PI * i / num + angle;
        qreal x_new = x + length * qCos(rad);
        qreal y_new = y - length * qSin(rad);

        painter->drawLine(QPointF(x, y), QPointF(x_new, y_new));
    }

    painter->drawEllipse(QPointF(x, y), 175.0, 175.0);
}

void Wheel::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space){
        press = !press;
    }

    update();
}
