/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x_it.h"
#include "leds.h"
//#include "bsp_timer.h"
#include "radiotimer.h"
#include "spi.h"
#include "radio.h"
// #include "rtc_timer.h"
// #include "uart.h"
// #include "debugpins.h"
#include "rcc.h"
#include <stdio.h>

#define ENABLE_DEBUG (0)
#include "debug.h"

void rtc_handler(void)
{
    DEBUG("%s\n",__PRETTY_FUNCTION__);
    if(RTC_GetFlagStatus(RTC_IT_ALR) != RESET)
    {
      RTC_ClearITPendingBit(RTC_IT_ALR);      //Clear RTC Alarm interrupt pending bit
      RTC_WaitForLastTask();                  //Wait until last write operation on RTC registers has finished
    }
}

void rtcalarm_handler(void)
{
    DEBUG("%s 1\n",__PRETTY_FUNCTION__);
  // debugpins_isr_set();
  if(EXTI_GetITStatus(EXTI_Line17) != RESET)
  {
	EXTI_ClearITPendingBit(EXTI_Line17);
    radiotimer_isr();
  }
  // debugpins_isr_clr();
}

void spi1_handler(void)
{
    DEBUG("%s\n",__PRETTY_FUNCTION__);
  // debugpins_isr_set();
  if(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != RESET)
  {
    spi_isr();
  }
  // debugpins_isr_clr();
}

void exti4_handler(void)
{
    DEBUG("%s\n",__PRETTY_FUNCTION__);
  if(EXTI_GetITStatus(EXTI_Line4) != RESET){
    // debugpins_isr_set();

    //leds_error_toggle();
    EXTI_ClearITPendingBit(EXTI_Line4);

    //RCC_Wakeup();
    radio_isr();

    // debugpins_isr_clr();
  }
}
