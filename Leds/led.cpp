#include "led.h"
#include <QPainter>

static const int LED_SIZE_IN_PX = 16;
static const int LED_DIAMETER_IN_PX = 12;

Led::Led()
{
    m_islit = false;
    this->setFixedSize(LED_SIZE_IN_PX,LED_SIZE_IN_PX);
}


void Led::lit(bool lit) {
    m_islit = lit;
}


void Led::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush drawBrush = QBrush();
    if (m_islit) {
        drawBrush.setColor(Qt::red);
        drawBrush.setStyle(Qt::SolidPattern);
    } else {
        drawBrush.setColor(Qt::black);
        drawBrush.setStyle(Qt::NoBrush);
    }
    painter.setBrush(drawBrush);
    int margin = (LED_SIZE_IN_PX-LED_DIAMETER_IN_PX) / 2;
    painter.drawEllipse(margin, margin, LED_DIAMETER_IN_PX, LED_DIAMETER_IN_PX);
};
