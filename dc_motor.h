 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC MOTOR driver
 *
 * Author: Samy Ibrahem
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT PORTB_ID
#define MOTOR_PIN1 PIN0_ID
#define MOTOR_PIN2 PIN1_ID
/*enum for motor state*/
typedef enum{
	STOP,CW,ACW
}DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC Motor driver.
 */
void DcMotor_Init(void);
/*
 * Description :
 * Function responsible for State the DC Motor driver.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
