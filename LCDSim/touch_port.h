#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TOUCH_EVENT_DOWN,
    TOUCH_EVENT_MOVE,
    TOUCH_EVENT_UP,
} touch_event_t;

void touch_port_input(touch_event_t event, int16_t x, int16_t y);

#ifdef __cplusplus
}
#endif
