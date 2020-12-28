#ifndef KEYBOARD
#define KEYBOARD

#include <lcom/lcf.h>

int(kbc_subscribe_int)(uint8_t *bit_no);

int(kbc_unsubscribe_int)();

void(kbc_ih)();

int kbc_issue_command(uint8_t cmd);

int kbc_get_command();

int kbc_restore_command();

int kbc_read_scancode();

#endif
