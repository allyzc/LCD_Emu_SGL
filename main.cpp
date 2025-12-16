#include <QApplication>
#include "LCDSim/lcdemulatorwidget.h"
#include "LCDSim/touch_port.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "sgl.h"

#define  CONFIG_SGL_PANEL_WIDTH         320
#define  CONFIG_SGL_PANEL_HEIGHT        240
#define  CONFIG_SGL_fb_buffer_LINE   40

QTimer timer_systick;             // systick_handler定时器

sgl_device_fb_t fb_dev;
sgl_color_t fb_buffer[CONFIG_SGL_PANEL_WIDTH * CONFIG_SGL_PANEL_HEIGHT];

void panel_flush_area(int16_t x, int16_t y, int16_t w, int16_t h, sgl_color_t *src)
{
//    sgl_color_t *dest = fb_buffer;
//    dest += (x + y * CONFIG_SGL_PANEL_WIDTH);

//    for(int i = 0; i < h; i ++) {
//        memcpy(dest, src, w * sizeof(sgl_color_t));
//        dest += CONFIG_SGL_PANEL_WIDTH;
//        src += w;
//    }
    //demo里面不是同一个，但也可以用同一个
    //并且flush里面不用写像素了，因为如果指定的是fb的VRAM，那么所有的图像数据会直接往VRAM写
}

static void mouse_event_interrupt(void)
{
    sgl_event_pos_t pos;

    if( tp_get_event()==TOUCH_EVENT_DOWN ) {
        pos.x = tp_get_x();
        pos.y = tp_get_y();
        sgl_event_send_pos(pos, SGL_EVENT_PRESSED);
    }
    else if( tp_get_event()==TOUCH_EVENT_UP ) {
        pos.x = tp_get_x();
        pos.y = tp_get_y();
        sgl_event_send_pos(pos, SGL_EVENT_RELEASED);
    }
    else if( tp_get_event()==TOUCH_EVENT_MOVE ) {
        pos.x = tp_get_x();
        pos.y = tp_get_y();
        sgl_event_send_pos(pos, SGL_EVENT_MOTION);
    }
}

/* 系统时钟中断服务函数，设置为1ms中断一次 */
void systick_handler(void)
{
    sgl_tick_inc(10);
    mouse_event_interrupt();
    sgl_task_handle();
}

extern "C" {
extern int sgl_demo(void);
}

void button_event_cb(sgl_event_t *evt)
{
    size_t para = evt->param;
    switch (evt->type) {
    case SGL_EVENT_PRESSED:
        qDebug("Button %d pressed\n", para);
        break;
    case SGL_EVENT_RELEASED:
        qDebug("Button %d released\n", para);
        break;
    }
}

int main(int argc,char**argv){
    QApplication a(argc,argv);

    LcdEmulatorWidget lcd(CONFIG_SGL_PANEL_WIDTH, CONFIG_SGL_PANEL_HEIGHT, (uint8_t*)fb_buffer, QImage::Format_BGR888);
    lcd.show();

    fb_dev.buffer[0]     = (void*)fb_buffer;
    fb_dev.buffer_size   = SGL_ARRAY_SIZE(fb_buffer);
    fb_dev.xres          = CONFIG_SGL_PANEL_WIDTH;
    fb_dev.yres          = CONFIG_SGL_PANEL_HEIGHT;
    fb_dev.xres_virtual  = CONFIG_SGL_PANEL_WIDTH;
    fb_dev.yres_virtual  = CONFIG_SGL_PANEL_HEIGHT;
    fb_dev.flush_area    = panel_flush_area;

    sgl_device_fb_register(&fb_dev);

    sgl_init();
    //sgl_obj_set_event_cb

    //sgl_demo();
    sgl_obj_t *rect = sgl_rect_create(NULL);
    sgl_obj_set_pos(rect, 10, 10);
    sgl_obj_set_size(rect, 160, 100);
    sgl_color_t color1;
    color1.ch.red = 0xff;
    color1.ch.green = 0x00;
    color1.ch.blue = 0x00;
    sgl_rect_set_color(rect, color1);

    sgl_obj_t *circle = sgl_circle_create(NULL);
    sgl_obj_set_pos(circle, 200, 20);
    sgl_obj_set_size(circle, 100, 100);
    color1.ch.red = 0x00;
    color1.ch.green = 0x00;
    color1.ch.blue = 0xff;
    sgl_circle_set_color(circle, color1);

    sgl_obj_t *button = sgl_button_create(NULL);
    sgl_obj_set_pos(button, 20, 150);
    sgl_obj_set_size(button, 200, 70);
    color1.ch.red = 0x00;
    color1.ch.green = 0xff;
    color1.ch.blue = 0x00;
    sgl_button_set_color(button, color1);
    sgl_button_set_radius(button, 50);
    sgl_button_set_border_width(button, 2);
    color1.ch.red = 0xff;
    color1.ch.green = 0x00;
    color1.ch.blue = 0x00;
    sgl_button_set_border_color(button, color1);
    sgl_button_set_alpha(button, 128);
    sgl_button_set_font(button, &consolas23);
    sgl_button_set_text(button, "Button: 1");
    sgl_obj_set_event_cb(button, button_event_cb, 123456);

    QObject::connect(&timer_systick, &QTimer::timeout, [](){
        systick_handler();
    });
    timer_systick.start(10);


    return a.exec();
}
