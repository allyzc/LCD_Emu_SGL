#include <QApplication>
#include "LCDSim/lcdemulatorwidget.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sgl.h>

QTimer timer_systick;             // systick_handler定时器

#define  CONFIG_SGL_PANEL_WIDTH         800
#define  CONFIG_SGL_PANEL_HEIGHT        480
#define  CONFIG_SGL_PANEL_BUFFER_LINE   40

sgl_color_t panel_buffer[CONFIG_SGL_PANEL_WIDTH * CONFIG_SGL_PANEL_HEIGHT];

void panel_flush_area(int16_t x, int16_t y, int16_t w, int16_t h, sgl_color_t *src)
{
    //demo里面不是同一个，但也可以用同一个
    //并且flush里面不用写像素了，因为如果指定的是fb的VRAM，那么所有的图像数据会直接往VRAM写
}

sgl_device_fb_t fb_dev;

/* 系统时钟中断服务函数，设置为1ms中断一次 */
void systick_handler(void)
{
    sgl_tick_inc(10);
    sgl_task_handle();
}

extern "C" {
extern int sgl_demo(void);
}

int main(int argc,char**argv){
    QApplication a(argc,argv);

    LcdEmulatorWidget lcd(CONFIG_SGL_PANEL_WIDTH, CONFIG_SGL_PANEL_HEIGHT, (uint8_t*)panel_buffer, QImage::Format_RGB32);
    lcd.show();

    fb_dev.buffer[0]     = (void*)panel_buffer;
    fb_dev.buffer_size   = SGL_ARRAY_SIZE(panel_buffer);
    fb_dev.xres          = CONFIG_SGL_PANEL_WIDTH;
    fb_dev.yres          = CONFIG_SGL_PANEL_HEIGHT;
    fb_dev.xres_virtual  = CONFIG_SGL_PANEL_WIDTH;
    fb_dev.yres_virtual  = CONFIG_SGL_PANEL_HEIGHT;
    fb_dev.flush_area    = panel_flush_area;

    sgl_device_fb_register(&fb_dev);

    sgl_init();

    sgl_demo();

    QObject::connect(&timer_systick, &QTimer::timeout, [](){
        systick_handler();
    });
    timer_systick.start(10);


    return a.exec();
}
