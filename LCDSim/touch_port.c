#include "touch_port.h"

int16_t g_tp_x;
int16_t g_tp_y;
touch_event_t g_tp_event;

void touch_port_input(touch_event_t event, int16_t x, int16_t y)
{
    g_tp_event = event;
    if( event==TOUCH_EVENT_UP ) {
        g_tp_x = x;
        g_tp_y = y;
    }
    else if( event==TOUCH_EVENT_DOWN ) {
        g_tp_x = x;
        g_tp_y = y;
    }
    else if( event==TOUCH_EVENT_MOVE ) {
        g_tp_x = x;
        g_tp_y = y;
    }
}

uint8_t tp_get_event(void)
{
    return g_tp_event;
}

int16_t tp_get_x(void)
{
    return g_tp_x;
}

int16_t tp_get_y(void)
{
    return g_tp_y;
}
