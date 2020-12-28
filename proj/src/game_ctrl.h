#ifndef GAME_CTRL
#define GAME_CTRL

#include "macros.h"
#include "video_gr.h"
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

struct sprite {
  uint16_t pos_x, pos_y;
  uint16_t width, height;
  uint32_t *data;
};

struct button {
  uint16_t pos_x, pos_y;
  uint16_t width, height;
};

struct present {
  uint16_t pos_x, pos_y;
  bool catched;
};

struct platform {
  uint16_t pos_x, pos_y;
  uint16_t width;
};

struct backgrounds_ {
  struct sprite *background_sp, *init_menu_sp, *paused_sp, *level_failed_1_sp, *level_failed_2_sp, *level_completed_sp, *instructions_sp, *instructions_txt, *instructions_front, *choose_player_front, *choose_player_back;
};

struct buttons_ {
  struct button main_single_player_button, main_instructions_button, main_exit_button;
  struct button paused_resume_button, paused_main_menu_button, paused_exit_button;
  struct button swipe_left, swipe_right, start;
  struct button failed_main_menu_button, failed_exit_button;
  struct button completed_main_menu_button, completed_exit_button;
  struct button instructions_home_button;
};

typedef enum { INITMENU,
               PAUSE,
               CHOOSE_PLAYER,
               INSTRUCTIONS_MENU,
               PLAYING,
               WON,
               TIME_OUT,
               IGLO,
               INSTRUCTIONS,
               EXIT } game_states;

typedef enum { STANDING_RIGHT,
               STANDING_LEFT,
               WALKING_RIGHT,
               WALKING_LEFT,
               JUMPING_RIGHT,
               JUMPING_LEFT,
               FALLING_RIGHT,
               FALLING,
               FALLING_LEFT,
               DEAD } santa_states;

typedef enum { ESC,
               LEFT,
               RIGHT,
               UP,
               RELEASED } keyboard_events;

typedef enum {
  HAPPY_SANTA,
  COVID_SANTA,
} player_states;

extern uint32_t *main_buf;
extern uint32_t *aux_buf;
extern game_states game_state;
extern santa_states santa_state;
extern player_states char_state;
extern keyboard_events keyboard_event;
extern struct sprite *sea_front;
extern struct sprite *sea_middle;
extern struct sprite *sea_back;
extern struct sprite current_bg;
extern struct sprite *cursor;
extern struct sprite **players;
extern struct sprite *curr_santa_sp;
extern struct sprite *santa_sp;
extern struct sprite *covid_santa_sp;
extern struct sprite *current_santa;
extern struct sprite **current_santa_walk_right;
extern struct sprite **current_santa_walk_left;
extern struct sprite **current_santa_jump_right;
extern struct sprite **current_santa_jump_left;
extern struct sprite **santa_walk_right;
extern struct sprite **santa_walk_left;
extern struct sprite **santa_jump_right;
extern struct sprite **santa_jump_left;
extern struct sprite **covid_santa_walk_right;
extern struct sprite **covid_santa_walk_left;
extern struct sprite **covid_santa_jump_right;
extern struct sprite **covid_santa_jump_left;
extern struct sprite **time_numbers;
extern struct sprite **current_time;
extern struct present *presents;
extern struct sprite *presents_animated;
extern struct sprite bigpresent;
struct backgrounds_ *backgrounds;
extern struct platform *platforms;
struct buttons_ *buttons;
extern uint8_t keyboard_data;
extern struct packet mouse_packet;
extern int i;
static int mouse_santa_sp_right_counter = 0;
static int mouse_santa_sp_left_counter = 0;
static int santa_sp_up_counter = 0;
static int santa_sp_down_counter = 0;
static int moving_right_counter = 0;
static int moving_left_counter = 0;
static bool moving_right = false;
static bool moving_left = false;
extern int presents_rot;
static int presents_catched = 0;
extern int timer_counter;
static unsigned cronometer;
static int instructions_ov_y = 270;
static unsigned int choose_player_ix = 0;

void update_display();

void update_display_player();

void update_display_instructions();

void update_playing_display();

void display_cronometer();

void display_presents();

bool check_button(uint8_t button);

int check_present();

void check_victory();

int check_right_left();

void catch_present(int present_ix);

void update_cronometer();

void update_cursor();

void update_santa_pos();

void reset_cronometer();

void set_santa(struct sprite *new_sp);

void set_player();

void reset_santa();

void reset_presents();

void mouse_events_handler_while_playing();

void mouse_events_handler();

void set_keyboard_events();

void keyboard_events_handler();

void timer_events_handler();

int get_current_platform();

void check_collision(uint16_t step);

void move_santa_keyboard();

void move_santa_mouse();

#endif
