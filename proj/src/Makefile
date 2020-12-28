PROG=proj

SRCS = proj.c game.c interface.c timer.c keyboard.c mouse.c rtc.c uart.c game_ctrl.c utils.c macros.h kbc.c video_gr.c

# __LCOM_OPTIMIZED__ disables most of the LCF's overhead (and functionality!)
CPPFLAGS += -pedantic #-D __LCOM_OPTIMIZED__

DPADD += ${LIBLCF}
LDADD += -llcf

.include <minix.lcom.mk>
