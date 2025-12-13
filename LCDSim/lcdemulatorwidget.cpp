#include "lcdemulatorwidget.h"
#include <QPainter>
#include <cstring>
#include <QDebug.h>

LcdEmulatorWidget::LcdEmulatorWidget(int w, int h, uint8_t *fbuffer, int format, QWidget *parent)
    : QWidget(parent),
    lcdWidth(w),
    lcdHeight(h)
{
    //fb = new uint8_t[w * h * 3];   // RGB888
    fb = fbuffer;
    imgFormat = format;
    //std::memset(fb, 0, w*h*3);

    setFixedSize(w+20, h+20);

    // 60Hz 刷新
    connect(&timer, &QTimer::timeout, this, &LcdEmulatorWidget::updateLcd);
    timer.start(33);
}

LcdEmulatorWidget::~LcdEmulatorWidget()
{
    //delete[] fb;
}

uint8_t* LcdEmulatorWidget::buffer()
{
    return fb;
}

int LcdEmulatorWidget::width()
{
    return lcdWidth;
}

int LcdEmulatorWidget::height()
{
    return lcdHeight;
}

void LcdEmulatorWidget::updateLcd()
{
    update();   // 触发 paintEvent()
}

void LcdEmulatorWidget::paintEvent(QPaintEvent *)
{
//    QImage img(fb, lcdWidth, lcdHeight, QImage::Format_RGB888);
    QImage img(fb, lcdWidth, lcdHeight, (QImage::Format)imgFormat);

    QPainter p(this);
    p.drawImage(10, 10, img);
}

void LcdEmulatorWidget::mousePressEvent(QMouseEvent *e)
{

}

void LcdEmulatorWidget::mouseReleaseEvent(QMouseEvent *e)
{

}

void LcdEmulatorWidget::mouseMoveEvent(QMouseEvent *e)
{
    qDebug() << "Mouse move:"<<e->pos();
}

