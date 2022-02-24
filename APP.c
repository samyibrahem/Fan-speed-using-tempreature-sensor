/******************************************************************************
 *
 * Module: MAIN FUNCTION
 *
 * File Name: APP.h
 *
 * Description: source file for the APPlication layer in my project
 *
 * Author: Samy Ibrahem
 *
 *******************************************************************************/
/********************************INCLUDES**************************************/
#include "adc.h"
#include "lcd.h"
#include "Lm35_sensor.h"
#include "pwm.h"
#include "dc_motor.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*my main Fucntion that run the code*/
int main(void)
{
	uint8 temp;/*variable to store the tempreature*/
	LCD_init(); /* initialize LCD driver */
	ADC_ConfigType ADC_config = {Internal, F_CPU_8 }; /*variable to contain ADC configurations*/
	ADC_init(&ADC_config);
	PWM_config PWM_Config = {NON_INVERTING,F_CPU8};/*variable to contain PWM configurations*/
	PWM_Timer0_init(&PWM_Config);
	DcMotor_Init();/*initialize DC MOTOR driver*/
	while(1){
		temp=LM35_GetTemperature(); /*get the value from tempreature sensor and store it in the temp variable*/
		if(temp < 30){/*if tempreature is less than 30*/
			DcMotor_Rotate(STOP,0);/*stop the motor & pwm produce no signal*/
			LCD_moveCursor(1,3);/*move the cursor to print the next word in middle*/
			LCD_displayString("FAN IS OFF");
			LCD_moveCursor(2,3);
			LCD_displayString("Temp=   C");
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);/*display the tempreature*/
		}
		else if(temp>= 30 && temp < 60){/*if tempreature more than or equal 30 and less than or equal 60*/
					DcMotor_Rotate(CW,64);/* turn the motor clock wise with speed equal 25% * PWM module (255) total signal*/
					LCD_moveCursor(1,3);
					LCD_displayString("FAN IS ON ");
					LCD_moveCursor(2,3);
					LCD_displayString("Temp=   C");
					LCD_moveCursor(2,8);
					LCD_intgerToString(temp);
				}
		else if(temp>= 60 && temp < 90){
							DcMotor_Rotate(CW,128);/* turn the motor clock wise with speed equal 50% * PWM module (255) total signal*/
							LCD_moveCursor(1,3);
							LCD_displayString("FAN IS ON ");
							LCD_moveCursor(2,3);
							LCD_displayString("Temp=   C");
							LCD_moveCursor(2,8);
							LCD_intgerToString(temp);
						}
		else if(temp>= 90 && temp < 120){
									DcMotor_Rotate(CW,191);/* turn the motor clock wise with speed equal 75% * PWM module (255) total signal*/
									LCD_moveCursor(1,3);
									LCD_displayString("FAN IS ON ");
									LCD_moveCursor(2,3);
									LCD_displayString("Temp=   C");
									LCD_moveCursor(2,8);
									LCD_intgerToString(temp);
								}
		else {
									DcMotor_Rotate(CW,255);/* turn the motor clock wise with full speed*/
									LCD_moveCursor(1,3);
									LCD_displayString("FAN IS ON ");
									LCD_moveCursor(2,3);
									LCD_displayString("Temp=   C");
									LCD_moveCursor(2,8);
									LCD_intgerToString(temp);
								}
	}

}
