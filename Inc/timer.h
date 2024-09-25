#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

void TIM2_IRQHandler();
void TIM2_Config(uint16_t prescaler, uint16_t arr);
void delay_ms(uint16_t ms);

#endif /* TIMER_H_ */
