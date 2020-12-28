#ifndef MOUSE
#define MOUSE

#include <lcom/lcf.h>

int(mouse_subscribe_int)(uint8_t *bit_no);

int(mouse_unsubscribe_int)();

void(mouse_ih)();

void mouse_process_byte();

int mouse_write(uint8_t cmd);

int check_obf();

int mouse_enable_data_report();

int mouse_disable_data_report();

#endif
