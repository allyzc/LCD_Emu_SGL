QT       += core gui widgets
CONFIG   += c++11 console
TEMPLATE = app
TARGET = LCD_Emu_Project

INCLUDEPATH += $$PWD/sgl-main/source
INCLUDEPATH += $$PWD/sgl-main/source/include

SOURCES += \
    main.cpp \
    sgl_demo.c \
    bg.c \
    test.c \
    LCDSim/lcdemulatorwidget.cpp \
    LCDSim/touch_port.c \
    sgl-main/source/core/sgl_anim.c \
    sgl-main/source/core/sgl_core.c \
    sgl-main/source/core/sgl_event.c \
    sgl-main/source/core/sgl_log.c \
    sgl-main/source/core/sgl_math.c \
    sgl-main/source/core/sgl_misc.c \
    sgl-main/source/draw/sgl_draw_arc.c \
    sgl-main/source/draw/sgl_draw_circle.c \
    sgl-main/source/draw/sgl_draw_icon.c \
    sgl-main/source/draw/sgl_draw_line.c \
    sgl-main/source/draw/sgl_draw_pie.c \
    sgl-main/source/draw/sgl_draw_rect.c \
    sgl-main/source/draw/sgl_draw_ring.c \
    sgl-main/source/draw/sgl_draw_text.c \
    sgl-main/source/fonts/sgl_ascii_consolas14.c \
    sgl-main/source/fonts/sgl_ascii_consolas23.c \
    sgl-main/source/fonts/sgl_ascii_consolas24.c \
    sgl-main/source/fonts/sgl_ascii_consolas34.c \
    sgl-main/source/fonts/sgl_ascii_song23.c \
    sgl-main/source/mm/lwmem/lwmem.c \
    sgl-main/source/mm/lwmem/sgl_mm.c \
    sgl-main/source/widgets/2dball/sgl_2dball.c \
    sgl-main/source/widgets/arc/sgl_arc.c \
    sgl-main/source/widgets/button/sgl_button.c \
    sgl-main/source/widgets/checkbox/sgl_checkbox.c \
    sgl-main/source/widgets/circle/sgl_circle.c \
    sgl-main/source/widgets/dropdown/sgl_dropdown.c \
    sgl-main/source/widgets/icon/sgl_icon.c \
    sgl-main/source/widgets/keyboard/sgl_keyboard.c \
    sgl-main/source/widgets/label/sgl_label.c \
    sgl-main/source/widgets/led/sgl_led.c \
    sgl-main/source/widgets/line/sgl_line.c \
    sgl-main/source/widgets/msgbox/sgl_msgbox.c \
    sgl-main/source/widgets/numberkbd/sgl_numberkbd.c \
    sgl-main/source/widgets/progress/sgl_progress.c \
    sgl-main/source/widgets/rectangle/sgl_rectangle.c \
    sgl-main/source/widgets/ring/sgl_ring.c \
    sgl-main/source/widgets/scope/sgl_scope.c \
    sgl-main/source/widgets/scroll/sgl_scroll.c \
    sgl-main/source/widgets/slider/sgl_slider.c \
    sgl-main/source/widgets/switch/sgl_switch.c \
    sgl-main/source/widgets/textbox/sgl_textbox.c \
    sgl-main/source/widgets/textline/sgl_textline.c

HEADERS += \
    LCDSim/lcdemulatorwidget.h \
    LCDSim/touch_port.h \
    sgl-main/source/include/sgl_anim.h \
    sgl-main/source/include/sgl_cfgfix.h \
    sgl-main/source/include/sgl_core.h \
    sgl-main/source/include/sgl_draw.h \
    sgl-main/source/include/sgl_errno.h \
    sgl-main/source/include/sgl_event.h \
    sgl-main/source/include/sgl_font.h \
    sgl-main/source/include/sgl_list.h \
    sgl-main/source/include/sgl_log.h \
    sgl-main/source/include/sgl_math.h \
    sgl-main/source/include/sgl_misc.h \
    sgl-main/source/include/sgl_mm.h \
    sgl-main/source/include/sgl_theme.h \
    sgl-main/source/include/sgl_types.h \
    sgl-main/source/mm/lwmem/lwmem.h \
    sgl-main/source/mm/lwmem/lwmem_opt.h \
    sgl-main/source/sgl.h \
    sgl-main/source/sgl_config.h \
    sgl-main/source/widgets/2dball/sgl_2dball.h \
    sgl-main/source/widgets/arc/sgl_arc.h \
    sgl-main/source/widgets/button/sgl_button.h \
    sgl-main/source/widgets/checkbox/sgl_checkbox.h \
    sgl-main/source/widgets/circle/sgl_circle.h \
    sgl-main/source/widgets/dropdown/sgl_dropdown.h \
    sgl-main/source/widgets/icon/sgl_icon.h \
    sgl-main/source/widgets/keyboard/sgl_keyboard.h \
    sgl-main/source/widgets/label/sgl_label.h \
    sgl-main/source/widgets/led/sgl_led.h \
    sgl-main/source/widgets/line/sgl_line.h \
    sgl-main/source/widgets/msgbox/sgl_msgbox.h \
    sgl-main/source/widgets/numberkbd/sgl_numberkbd.h \
    sgl-main/source/widgets/progress/sgl_progress.h \
    sgl-main/source/widgets/rectangle/sgl_rectangle.h \
    sgl-main/source/widgets/ring/sgl_ring.h \
    sgl-main/source/widgets/scope/sgl_scope.h \
    sgl-main/source/widgets/scroll/sgl_scroll.h \
    sgl-main/source/widgets/slider/sgl_slider.h \
    sgl-main/source/widgets/switch/sgl_switch.h \
    sgl-main/source/widgets/textbox/sgl_textbox.h \
    sgl-main/source/widgets/textline/sgl_textline.h


QMAKE_CFLAGS += -std=c99


