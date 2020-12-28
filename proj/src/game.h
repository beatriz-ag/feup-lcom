#ifndef GAME
#define GAME

#include "game_ctrl.h"
#include "kbc.h"
#include "keyboard.h"
#include "macros.h"
#include "mouse.h"
#include "rtc.h"
#include "video_gr.h"
#include "xpms.h"
#include <lcom/lcf.h>

/*struct with background sprites*/
struct backgrounds_ *backgrounds;

/*struct with buttons info*/
struct buttons_ *buttons;

void set_display();

struct sprite *get_sprite(xpm_map_t xpm, int x, int y);

void load_xpms();

void set_presents();

void set_buttons();

void set_platforms();

void set_up();

void restore();

int init_game();

int pause();

int playing();

#endif
