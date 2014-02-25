/**
\brief iot-lab_M3 definition of the "leds" bsp module.

\author Alaeddine Weslati <alaeddine.weslati@inria.fr>, January 2014.
*/

#include "stm32f10x_lib.h"
#include "leds_ow.h"

//=========================== defines =========================================
#define LED_RED_PIN             (1<<2)
#define LED_GREEN_PIN           (1<<5)
#define LED_ORANGE_PIN          (1<<10)

//=========================== variables =======================================

//=========================== prototypes ======================================

void Delay(void);

//=========================== public ==========================================

void leds_init_ow(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

// red
void leds_error_on(void)
{
  GPIOD->ODR &= ~LED_RED_PIN;
}
void leds_error_off(void)
{
  GPIOD->ODR |= LED_RED_PIN;
}
void leds_error_toggle(void)
{
  GPIOD->ODR ^= LED_RED_PIN;
}
uint8_t leds_error_isOn(void)
{
  u8 bitstatus = 0x00;
  if ((GPIOD->ODR & LED_RED_PIN) != (u32)0)
  {
    bitstatus = 0x00;
  }
  else
  {
    bitstatus = 0x01;
  }
  return bitstatus;
}
void leds_error_blink(void) {}

// green
void leds_sync_on(void)
{
  GPIOB->ODR &= ~LED_GREEN_PIN;
}
void leds_sync_off(void)
{
  GPIOB->ODR |= LED_GREEN_PIN;
}
void leds_sync_toggle(void)
{
  GPIOB->ODR ^= LED_GREEN_PIN;
}
uint8_t leds_sync_isOn(void)
{
  u8 bitstatus = 0x00;
  if ((GPIOB->ODR & LED_GREEN_PIN) != (u32)0)
  {
    bitstatus = 0x00;
  }
  else
  {
    bitstatus = 0x01;
  }
  return bitstatus;
}

// orange
void leds_radio_on(void)
{
  GPIOC->ODR &= ~LED_ORANGE_PIN;
}
void leds_radio_off(void)
{
  GPIOC->ODR |= LED_ORANGE_PIN;
}
void leds_radio_toggle(void)
{
  GPIOC->ODR ^= LED_ORANGE_PIN;
}
uint8_t leds_radio_isOn(void)
{
  u8 bitstatus = 0x00;
  if ((GPIOC->ODR & LED_ORANGE_PIN) != (u32)0)
  {
    bitstatus = 0x00;
  }
  else
  {
    bitstatus = 0x01;
  }
  return bitstatus;
}
// yellow
void leds_debug_on(void) {}
void leds_debug_off(void) {}
void leds_debug_toggle(void) {}
uint8_t leds_debug_isOn(void) {}

void leds_all_on(void)
{
  leds_error_on();
  leds_sync_on();
  leds_radio_on();
}
void leds_all_off(void)
{
  leds_error_off();
  leds_sync_off();
  leds_radio_off();
}
void leds_all_toggle(void)
{
  leds_error_toggle();
  leds_sync_toggle();
  leds_radio_toggle();
}

void leds_circular_shift(void)
{
  leds_error_toggle();
  Delay();
  leds_sync_toggle();
  Delay();
  leds_radio_toggle();
  Delay();
}

void leds_increment(void) {}

//=========================== private =========================================

void Delay(void)
{
  uint32_t i;
  for(i=0; i<0xfffff; i++);
}

