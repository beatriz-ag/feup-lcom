#ifndef KBC
#define KBC

#include <lcom/lcf.h>

int kbc_write(uint8_t port, uint8_t cmd);

int kbc_read(uint8_t *arg);

bool mouse_int();

#endif
