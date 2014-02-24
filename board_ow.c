#include "msp430f1611.h"
#include "board_ow.h"

#include "leds.h"
#include "uart_ow.h"
#include "spi.h"
//#include "bsp_timer.h"
#include "radio.h"
#include "radiotimer.h"

void board_init_ow() {
   puts(__PRETTY_FUNCTION__);
   //disable watchdog timer
   WDTCTL     =  WDTPW + WDTHOLD;
   
   //setup clock speed
   DCOCTL    |=  DCO0 | DCO1 | DCO2;             // MCLK at ~8MHz
   BCSCTL1   |=  RSEL0 | RSEL1 | RSEL2;          // MCLK at ~8MHz
                                                 // by default, ACLK from 32kHz XTAL which is running
   
   // initialize pins
   P4DIR     |=  0x20;                           // [P4.5] radio VREG:  output
     P4DIR     |=  0x40;                           // [P4.6] radio reset: output
   
   // initialize bsp modules
   // debugpins_init();
    // leds_init();
   // uart_init_ow();
   // spi_init();
//    bsp_timer_init();
//    radio_init();
//    radiotimer_init();
   
   // enable interrupts
    // __bis_SR_register(GIE);
}

void board_reset() {
   WDTCTL = (WDTPW+0x1200) + WDTHOLD; // writing a wrong watchdog password to causes handler to reset
}

void board_sleep() {
   __bis_SR_register(GIE+LPM0_bits);             // sleep, but leave ACLK on
}
// ISR(COMPARATORA) {
//    //debugpins_isr_set();
//    __bic_SR_register_on_exit(CPUOFF);            // restart CPU
//    //debugpins_isr_clr();
// }

ISR(TIMERB1) {
   //debugpins_isr_set();
   if (radiotimer_isr()==KICK_SCHEDULER) {       // radiotimer
      __bic_SR_register_on_exit(CPUOFF);
   }
   //debugpins_isr_clr();
}

// ISR(TIMERA0) {
//    //debugpins_isr_set();
//    if (bsp_timer_isr()==KICK_SCHEDULER) {        // timer: 0
//       __bic_SR_register_on_exit(CPUOFF);
//    }
//    //debugpins_isr_clr();
// }
