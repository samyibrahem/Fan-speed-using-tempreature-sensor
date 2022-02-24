 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the DC MOTOR driver
 *
 * Author: Samy Ibrahem
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "PWM.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC Motor driver.
 */
void DcMotor_Init(void){
	 GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN1,PIN_OUTPUT);/* motor pin1 output*/
	 GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN2,PIN_OUTPUT);/* motor pin1 output*/
	  GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);/* STOP MOTOR AT START*/
	  GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	PWM_Timer0_Start(speed);
	switch(state){
	case 0 :
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);/* STOP MOTOR*/
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_LOW);
		  break;
	case 1:
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_HIGH);/* CLOCKWISE MOTOR*/
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_LOW);
		  break;
	case 2:
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN1,LOGIC_LOW);/* CLOCKWISE MOTOR*/
		  GPIO_writePin(MOTOR_PORT,MOTOR_PIN2,LOGIC_HIGH);
		  break;

	}
}
