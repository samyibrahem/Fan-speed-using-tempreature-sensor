 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Samy Ibrahem
 *
 *******************************************************************************/
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"
#include "common_macros.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void PWM_Timer0_init(PWM_config *config_ptr){

	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT); /*PB3 As output to produce pwm signal*/
	/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 = (TCCR0 & 0xCF) | ((config_ptr->mode)<<4);
	TCCR0 = (TCCR0 &0xF8) | ((config_ptr->prescaler));
	TCNT0=0; /* counter start counting from 0*/
}

void PWM_Timer0_Start(uint8 duty_cycle){
	OCR0=duty_cycle; /*compare value */
}

