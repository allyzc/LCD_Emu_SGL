#include "touch_port.h"
#include "sgl.h"   // 或 emWin / lvgl

void touch_port_input(touch_event_t event, int16_t x, int16_t y)
{
  sgl_event_pos_t pos;

  if( event==TOUCH_EVENT_UP ) {
      pos.x = x;
      pos.y = y;
      sgl_event_send_pos(pos, SGL_EVENT_RELEASED);
  }
  else if( event==TOUCH_EVENT_DOWN ) {
      pos.x = x;
      pos.y = y;
      sgl_event_send_pos(pos, SGL_EVENT_PRESSED);
  }
  else if( event==TOUCH_EVENT_MOVE ) {
      pos.x = x;
      pos.y = y;
      sgl_event_send_pos(pos, SGL_EVENT_MOTION);
  }
}
