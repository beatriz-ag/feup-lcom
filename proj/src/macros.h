#ifndef MACROS
#define MACROS

#include <lcom/lcf.h>

//TIMER

#define TIMER_FREQ 1193182 /**< @brief clock frequency for timer in PC and AT */
#define TIMER0_IRQ 0       /**< @brief Timer 0 IRQ line */

/* I/O port addresses */

#define TIMER_0 0x40    /**< @brief Timer 0 count register */
#define TIMER_1 0x41    /**< @brief Timer 1 count register */
#define TIMER_2 0x42    /**< @brief Timer 2 count register */
#define TIMER_CTRL 0x43 /**< @brief Control register */

#define SPEAKER_CTRL 0x61 /**< @brief Register for speaker control  */

/* Timer control */

/* Timer selection: bits 7 and 6 */

#define TIMER_SEL0 0x00                /**< @brief Control Word for Timer 0 */
#define TIMER_SEL1 BIT(6)              /**< @brief Control Word for Timer 1 */
#define TIMER_SEL2 BIT(7)              /**< @brief Control Word for Timer 2 */
#define TIMER_RB_CMD (BIT(7) | BIT(6)) /**< @brief Read Back Command */

/* Register selection: bits 5 and 4 */

#define TIMER_LSB BIT(4)                      /**< @brief Initialize Counter LSB only */
#define TIMER_MSB BIT(5)                      /**< @brief Initialize Counter MSB only */
#define TIMER_LSB_MSB (TIMER_LSB | TIMER_MSB) /**< @brief Initialize LSB first and MSB afterwards */

/* Operating mode: bits 3, 2 and 1 */

#define TIMER_SQR_WAVE (BIT(2) | BIT(1)) /**< @brief Mode 3: square wave generator */
#define TIMER_RATE_GEN BIT(2)            /**< @brief Mode 2: rate generator */

/* Counting mode: bit 0 */

#define TIMER_BCD 0x01 /**< @brief Count in BCD */
#define TIMER_BIN 0x00 /**< @brief Count in binary */

/* READ-BACK COMMAND FORMAT */

#define TIMER_RB_COUNT_ BIT(5)
#define TIMER_RB_STATUS_ BIT(4)
#define TIMER_RB_SEL(n) BIT((n) + 1)

// KBC

#define KBC_ST_REG 0x64  //status register
#define KBC_CMD_REG 0x64 //command register/byte
#define KBC_OUT_BUF 0x60 //output buffer

#define KBC_OBF BIT(0)     //output buffer full
#define KBC_IBF BIT(1)     //input buffer full
#define AUX BIT(5)         //mouse data
#define KBC_TO_ERR BIT(6)  //timeout error
#define KBC_PAR_ERR BIT(7) //parity error
#define EN_KBD 0xAE        //enable KBD interface
#define DIS_KBD 0xAD       //disable KBD interface

/*MOUSE RELATED KBC COMMANDS*/
#define READ_CB 0x20     //read command byte
#define WRITE_CB 0x60    //write command byte
#define EN_MOUSE 0xA8    //enable mouse
#define DIS_MOUSE 0xA7   //disable mouse
#define CHECK_INTER 0xA9 //check mouse interface
#define WRITE_BYTE 0xD4  //write byte to mouse

/*STATUS REGISTER*/
#define PARITY BIT(7)  //parity error
#define TIMEOUT BIT(6) //timeout error
#define AUX BIT(5)     //mouse data
#define A2 BIT(3)      //A2 input line, 0: data byte, 1: command byte
#define SYS BIT(2)     //system flag, 0: system in power-on reset, 1: system already initialized
#define IBF BIT(1)     //input buffer full
#define OBF BIT(0)     //output buffer full

/*KBC COMMAND BYTE*/
#define INT BIT(0)  //enable interrupt on OUT_BUF, from keyboard
#define INT2 BIT(1) //enable interrupt on OUT_BUF, from mouse
#define DIS BIT(4)  //disable keyboard interface
#define DIS2 BIT(5) //disable mouse interface

/*MOUSE COMMANDS*/
#define RESET 0xFF           //mouse reset
#define RESEND 0xFE          //for serial communications errors
#define SET_DEFAULTS 0xF6    //set default values
#define DISABLE 0xF5         //in stream mode, should be sent before any other command
#define ENABLE 0xF4          //in stream mode only
#define SET_SAMPLE_RATE 0xF3 //sets state sampling rate
#define SET_REMOTE_MODE 0xF0 //send data on request only
#define READ_DATA 0xEB       //send data packet request
#define SET_STREAM_MODE 0xFA //send data on events
#define STATUS_REQUEST 0xF9  //get mouse configuration
#define SET_RESOLUTION 0xF8
#define SET_SCALING_21 0xF7 //acceleration mode
#define SET_SCALING_11 0xF6 //linear mode

/*MOUSE CONTROLLER ACKNOWLEDGMENT BYTE*/
#define ACK 0xFA   //everything ok
#define NACK 0xFE  //invalid byte
#define ERROR 0xFC //second consecutive invalid byte
#define REMOTE 0xF0
#define STREAM 0xEA

#define WAIT_KBC 20000
#define KBC_IRQ 1
#define TIMER0_IRQ 0 //timer 0 line
#define MOUSE_IRQ 12 //mouse line
#define BREAK_ESC 0x81

/*COMMAND BYTE 1 BITS MEANING */

#define LB BIT(0)
#define RB BIT(1)
#define MB BIT(2)
#define MSB_X_DELTA BIT(4)
#define MSB_Y_DELTA BIT(5)
#define X_OV BIT(6)
#define Y_OV BIT(7)

/*BUTTONS*/

#define MAIN_SINGLE_PLAYER 11
#define MAIN_INSTRUCTIONS 12
#define MAIN_EXIT 13
#define PAUSED_RESUME 21
#define PAUSED_MAIN_MENU 22
#define PAUSED_EXIT 23
#define WON_MAIN_MENU 31
#define WON_EXIT 32
#define FAILED_MAIN_MENU 41
#define FAILED_EXIT 42
#define SWIPE_LEFT 51
#define SWIPE_RIGHT 52
#define START 53
#define INSTRUCTIONS_HOME_BUTTON 6

/*KEYBOARD*/

#define MAKE_UP_ARROW 0x48
#define MAKE_LEFT_ARROW 0x4B
#define MAKE_RIGHT_ARROW 0x4D
#define MAKE_UP_W 0x11
#define MAKE_LEFT_A 0x1E
#define MAKE_RIGHT_B 0x20
#define BREAK_ESC 0x81

/* RTC */
#define RTC_IRQ 8
#define RTC_ADDR_REG 0x70
#define RTC_DATA_REG 0x71
#define RTC_SECONDS 0
#define RTC_MINUTES 2
#define RTC_HOURS 4
#define RTC_DAY_OF_MONTH 7
#define RTC_MONTH 8
#define RTC_YEAR 9
#define RTC_REG_A 10
#define RTC_REG_B 11
#define RTC_REG_C 12
#define RTC_REG_A_UI BIT(7)
#define RTC_REG_B_SET BIT(7)  //set to 1 to inhibit updates of time/date registers
#define RTC_REG_B_PI BIT(6)   //set to 1 to enable periodic interrupts
#define RTC_REG_B_AI BIT(5)   //set to 1 to enable alarm interrupts
#define RTC_REG_B_UI BIT(4)   //set to 1 to enable update interrupts
#define RTC_REG_B_DM BIT(2)   //set to 1 to set registers in binary, set to 0 for BCD
#define RTC_REG_B_2412 BIT(1) //set to 1 to set hours range from 0 to 23, set to 0 to range from 1 to 12
#define RTC_REG_C_IRQF BIT(7) //if set, IRQ line pending
#define RTC_REG_C_PF BIT(6)   //if set, periodic interrupt pending
#define RTC_REG_C_AF BIT(5)   //if set, alarm interrupt pending
#define RTC_REG_C_UE BIT(4)   //if set, update interrupt pending

/* OTHER GAME MACROS */

#define WAIT 200
#define STEP_KB 4
#define STEP_JUMP_X 4
#define STEP_JUMP_Y 12
#define STEP_TXT 10
#define DELTA_Y 10
#define NUM_PRESENTS 6
#define NUM_PLATFORMS 9
#define TIME_LIMIT 240
#define SEA_BACK_X0 470
#define SEA_MIDDLE_X0 440
#define WAVE_WIDTH 77
#define HALF_SECOND_TICKS 30
#define SECOND_TICKS 60
#define IN_POS_X 445
#define OUT_LEFT_POS_X 107
#define OUT_RIGHT_POS_X 810

#endif
