/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _D51_UTIL_H_
#define _D51_UTIL_H_

#include "samd51j18a.h"

/* Debug LED */
#if DEBUG_LED_ENABLE == 1
#define DBG_LED_ENA PORT->Group[DEBUG_LED_PORT].DIRSET.reg = (1 << DEBUG_LED_PIN)
#define DBG_LED_DIS PORT->Group[DEBUG_LED_PORT].DIRCLR.reg = (1 << DEBUG_LED_PIN)
#define DBG_LED_ON PORT->Group[DEBUG_LED_PORT].OUTSET.reg = (1 << DEBUG_LED_PIN)
#define DBG_LED_OFF PORT->Group[DEBUG_LED_PORT].OUTCLR.reg = (1 << DEBUG_LED_PIN)
#else
#define DBG_LED_ENA
#define DBG_LED_DIS
#define DBG_LED_ON
#define DBG_LED_OFF
#endif

/* Debug Port 1 */
#if DEBUG_PORT1_ENABLE == 1
#define DBG_1_ENA PORT->Group[DEBUG_PORT1_PORT].DIRSET.reg = (1 << DEBUG_PORT1_PIN)
#define DBG_1_DIS PORT->Group[DEBUG_PORT1_PORT].DIRCLR.reg = (1 << DEBUG_PORT1_PIN)
#define DBG_1_ON PORT->Group[DEBUG_PORT1_PORT].OUTSET.reg = (1 << DEBUG_PORT1_PIN)
#define DBG_1_OFF PORT->Group[DEBUG_PORT1_PORT].OUTCLR.reg = (1 << DEBUG_PORT1_PIN)
#else
#define DBG_1_ENA
#define DBG_1_DIS
#define DBG_1_ON
#define DBG_1_OFF
#endif

/* Debug Port 2 */
#if DEBUG_PORT2_ENABLE == 1
#define DBG_2_ENA PORT->Group[DEBUG_PORT2_PORT].DIRSET.reg = (1 << DEBUG_PORT2_PIN)
#define DBG_2_DIS PORT->Group[DEBUG_PORT2_PORT].DIRCLR.reg = (1 << DEBUG_PORT2_PIN)
#define DBG_2_ON PORT->Group[DEBUG_PORT2_PORT].OUTSET.reg = (1 << DEBUG_PORT2_PIN)
#define DBG_2_OFF PORT->Group[DEBUG_PORT2_PORT].OUTCLR.reg = (1 << DEBUG_PORT2_PIN)
#else
#define DBG_2_ENA
#define DBG_2_DIS
#define DBG_2_ON
#define DBG_2_OFF
#endif

/* Debug Port 3 */
#if DEBUG_PORT3_ENABLE == 1
#define DBG_3_ENA PORT->Group[DEBUG_PORT3_PORT].DIRSET.reg = (1 << DEBUG_PORT3_PIN)
#define DBG_3_DIS PORT->Group[DEBUG_PORT3_PORT].DIRCLR.reg = (1 << DEBUG_PORT3_PIN)
#define DBG_3_ON PORT->Group[DEBUG_PORT3_PORT].OUTSET.reg = (1 << DEBUG_PORT3_PIN)
#define DBG_3_OFF PORT->Group[DEBUG_PORT3_PORT].OUTCLR.reg = (1 << DEBUG_PORT3_PIN)
#else
#define DBG_3_ENA
#define DBG_3_DIS
#define DBG_3_ON
#define DBG_3_OFF
#endif

void dbg_print(uint32_t x);
void dled_print(uint32_t x, uint8_t long_pause);

void debug_code_init(void);
void debug_code_disable(void);

#ifdef DEBUG_BOOT_TRACING_ENABLE

#define DBGC(n) debug_code = n

extern volatile uint32_t debug_code;

enum debug_code_list {
    DC_UNSET = 0,
    DC_CLK_INIT_BEGIN,
    DC_CLK_INIT_COMPLETE,
    DC_CLK_SET_I2C1_FREQ_BEGIN,
    DC_CLK_SET_I2C1_FREQ_COMPLETE,
    DC_CLK_SET_I2C0_FREQ_BEGIN,
    DC_CLK_SET_I2C0_FREQ_COMPLETE,
    DC_CLK_SET_SPI_FREQ_BEGIN,
    DC_CLK_SET_SPI_FREQ_COMPLETE,
    DC_CLK_ENABLE_TIMEBASE_BEGIN,
    DC_CLK_ENABLE_TIMEBASE_SYNC_ENABLE,
    DC_CLK_ENABLE_TIMEBASE_SYNC_SWRST_1,
    DC_CLK_ENABLE_TIMEBASE_SYNC_SWRST_2,
    DC_CLK_ENABLE_TIMEBASE_TC4_BEGIN,
    DC_CLK_ENABLE_TIMEBASE_TC4_SYNC_DISABLE,
    DC_CLK_ENABLE_TIMEBASE_TC4_SYNC_SWRST_1,
    DC_CLK_ENABLE_TIMEBASE_TC4_SYNC_SWRST_2,
    DC_CLK_ENABLE_TIMEBASE_TC4_SYNC_CLTRB,
    DC_CLK_ENABLE_TIMEBASE_TC4_SYNC_CC0,
    DC_CLK_ENABLE_TIMEBASE_TC4_COMPLETE,
    DC_CLK_ENABLE_TIMEBASE_TC5_BEGIN,
    DC_CLK_ENABLE_TIMEBASE_TC5_SYNC_DISABLE,
    DC_CLK_ENABLE_TIMEBASE_TC5_SYNC_SWRST_1,
    DC_CLK_ENABLE_TIMEBASE_TC5_SYNC_SWRST_2,
    DC_CLK_ENABLE_TIMEBASE_TC5_SYNC_CLTRB,
    DC_CLK_ENABLE_TIMEBASE_TC5_COMPLETE,
    DC_CLK_ENABLE_TIMEBASE_TC0_BEGIN,
    DC_CLK_ENABLE_TIMEBASE_TC0_SYNC_DISABLE,
    DC_CLK_ENABLE_TIMEBASE_TC0_SYNC_SWRST_1,
    DC_CLK_ENABLE_TIMEBASE_TC0_SYNC_SWRST_2,
    DC_CLK_ENABLE_TIMEBASE_TC0_COMPLETE,
    DC_CLK_ENABLE_TIMEBASE_EVSYS_BEGIN,
    DC_CLK_ENABLE_TIMEBASE_EVSYS_COMPLETE,
    DC_CLK_ENABLE_TIMEBASE_COMPLETE,
    DC_CLK_SET_GCLK_FREQ_BEGIN,
    DC_CLK_SET_GCLK_FREQ_SYNC_1,
    DC_CLK_SET_GCLK_FREQ_SYNC_2,
    DC_CLK_SET_GCLK_FREQ_SYNC_3,
    DC_CLK_SET_GCLK_FREQ_SYNC_4,
    DC_CLK_SET_GCLK_FREQ_SYNC_5,
    DC_CLK_SET_GCLK_FREQ_COMPLETE,
    DC_CLK_INIT_OSC_BEGIN,
    DC_CLK_INIT_OSC_SYNC_1,
    DC_CLK_INIT_OSC_SYNC_2,
    DC_CLK_INIT_OSC_SYNC_3,
    DC_CLK_INIT_OSC_SYNC_4,
    DC_CLK_INIT_OSC_SYNC_5,
    DC_CLK_INIT_OSC_COMPLETE,
    DC_CLK_RESET_TIME_BEGIN,
    DC_CLK_RESET_TIME_COMPLETE,
    DC_CLK_OSC_INIT_BEGIN,
    DC_CLK_OSC_INIT_XOSC0_SYNC,
    DC_CLK_OSC_INIT_DPLL_SYNC_DISABLE,
    DC_CLK_OSC_INIT_DPLL_SYNC_RATIO,
    DC_CLK_OSC_INIT_DPLL_SYNC_ENABLE,
    DC_CLK_OSC_INIT_DPLL_WAIT_LOCK,
    DC_CLK_OSC_INIT_DPLL_WAIT_CLKRDY,
    DC_CLK_OSC_INIT_GCLK_SYNC_GENCTRL0,
    DC_CLK_OSC_INIT_COMPLETE,
    DC_SPI_INIT_BEGIN,
    DC_SPI_WRITE_DRE,
    DC_SPI_WRITE_TXC_1,
    DC_SPI_WRITE_TXC_2,
    DC_SPI_SYNC_ENABLING,
    DC_SPI_INIT_COMPLETE,
    DC_PORT_DETECT_INIT_BEGIN,
    DC_PORT_DETECT_INIT_FAILED,
    DC_PORT_DETECT_INIT_COMPLETE,
    DC_USB_RESET_BEGIN,
    DC_USB_RESET_COMPLETE,
    DC_USB_SET_HOST_BY_VOLTAGE_BEGIN,
    DC_USB_SET_HOST_5V_LOW_WAITING,
    DC_USB_SET_HOST_BY_VOLTAGE_COMPLETE,
    DC_USB_CONFIGURE_BEGIN,
    DC_USB_CONFIGURE_GET_SERIAL,
    DC_USB_CONFIGURE_COMPLETE,
    DC_USB_WRITE2422_BLOCK_BEGIN,
    DC_USB_WRITE2422_BLOCK_SYNC_SYSOP,
    DC_USB_WRITE2422_BLOCK_COMPLETE,
    DC_ADC0_CLOCK_INIT_BEGIN,
    DC_ADC0_CLOCK_INIT_COMPLETE,
    DC_ADC0_INIT_BEGIN,
    DC_ADC0_SWRST_SYNCING_1,
    DC_ADC0_SWRST_SYNCING_2,
    DC_ADC0_AVGCTRL_SYNCING_1,
    DC_ADC0_AVGCTRL_SYNCING_2,
    DC_ADC0_SAMPCTRL_SYNCING_1,
    DC_ADC0_ENABLE_SYNCING_1,
    DC_ADC0_INIT_COMPLETE,
    DC_I2C0_INIT_BEGIN,
    DC_I2C0_INIT_SYNC_ENABLING,
    DC_I2C0_INIT_SYNC_SYSOP,
    DC_I2C0_INIT_WAIT_IDLE,
    DC_I2C0_INIT_COMPLETE,
    DC_I2C1_INIT_BEGIN,
    DC_I2C1_INIT_SYNC_ENABLING,
    DC_I2C1_INIT_SYNC_SYSOP,
    DC_I2C1_INIT_WAIT_IDLE,
    DC_I2C1_INIT_COMPLETE,
    DC_I2C3733_INIT_CONTROL_BEGIN,
    DC_I2C3733_INIT_CONTROL_COMPLETE,
    DC_I2C3733_INIT_DRIVERS_BEGIN,
    DC_I2C3733_INIT_DRIVERS_COMPLETE,
    DC_I2C_DMAC_LED_INIT_BEGIN,
    DC_I2C_DMAC_LED_INIT_COMPLETE,
    DC_I2C3733_CONTROL_SET_BEGIN,
    DC_I2C3733_CONTROL_SET_COMPLETE,
    DC_LED_MATRIX_INIT_BEGIN,
    DC_LED_MATRIX_INIT_COMPLETE,
    DC_USB2422_INIT_BEGIN,
    DC_USB2422_INIT_WAIT_5V_LOW,
    DC_USB2422_INIT_OSC_SYNC_DISABLING,
    DC_USB2422_INIT_OSC_SYNC_DFLLCTRLB_1,
    DC_USB2422_INIT_OSC_SYNC_DFLLCTRLB_2,
    DC_USB2422_INIT_OSC_SYNC_DFLLCTRLB_3,
    DC_USB2422_INIT_OSC_SYNC_DFLLCTRLB_4,
    DC_USB2422_INIT_OSC_SYNC_DFLLMUL,
    DC_USB2422_INIT_OSC_SYNC_ENABLING,
    DC_USB2422_INIT_USB_SYNC_SWRST,
    DC_USB2422_INIT_USB_WAIT_SWRST,
    DC_USB2422_INIT_USB_SYNC_ENABLING,
    DC_USB2422_INIT_COMPLETE,
    DC_MAIN_UDC_START_BEGIN,
    DC_MAIN_UDC_START_COMPLETE,
    DC_MAIN_CDC_INIT_BEGIN,
    DC_MAIN_CDC_INIT_COMPLETE,
    /* Never change the order of error codes! Only add codes to end! */
};

#else

#define DBGC(n) \
    {}

#endif  // DEBUG_BOOT_TRACING_ENABLE

#endif  //_D51_UTIL_H_
