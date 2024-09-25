#include "stm32f1xx.h"
#include "timer.h"
#include <stdint.h>

void TIM2_IRQHandler() {
    if(TIM2->SR & TIM_SR_UIF) {
        GPIOB->ODR ^= (1 << 11);

        TIM2->SR &= ~TIM_SR_UIF;
    }
}

void TIM2_Config(uint16_t prescaler, uint16_t arr) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;


    TIM2->PSC = prescaler - 1;
    TIM2->ARR = arr - 1;

    TIM2->DIER |= TIM_DIER_UIE;

    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CR1 |= TIM_CR1_CEN;
}

void delay_ms(uint16_t ms) {

    TIM2_Config(8000, ms);

    while(!(TIM2->SR & TIM_SR_UIF));

    TIM2->SR &= ~TIM_SR_UIF;

    TIM2->CR1 &= ~TIM_CR1_CEN;
}
