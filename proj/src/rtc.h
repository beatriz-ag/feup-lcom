#ifndef RTC
#define RTC

#include <lcom/lcf.h>

struct date_t {
  uint8_t day;
  uint8_t month;
  uint8_t year;
};

struct time_t {
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
};

extern struct time_t curr_time;
extern struct date_t curr_date;

int rtc_subscribe_int(uint8_t *bit_no);

int rtc_unsubscribe_int();

int rtc_write_command(uint8_t reg);

int rtc_enable_ints(uint8_t source);

int rtc_disable_ints(uint8_t source);

int rtc_read_date();

int rtc_read_time();

int rtc_set_BCD();

void BCD_to_binary(uint8_t value);

bool rtc_reading_allowed();

void rtc_ih(uint8_t source);

#endif
