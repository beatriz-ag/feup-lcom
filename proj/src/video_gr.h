#ifndef VIDEO_GR
#define VIDEO_GR

#include <lcom/lcf.h>

void(get_mode_info)(uint16_t mode, vbe_mode_info_t *mode_info);

int(map_vr)(vbe_mode_info_t mode_info);

void set_info(uint16_t mode, vbe_mode_info_t mode_info);

void *(vg_init)(uint16_t mode);

int set_pixel(uint32_t *buffer, int x, int y, uint32_t img);

int display_xpm(uint32_t *buffer, uint32_t *map, int x, int y, uint16_t width, uint16_t height);

int clear_buffer(uint32_t *buffer);

int page_flipping(uint32_t *main_buf, uint32_t *aux_buf);

unsigned get_h_res();

unsigned get_v_res();

#endif
