/*
 ================================================================================================
 Name        : measure_distance.c
 Author      : Abdelrahman Youssef
 Description : Measure distance using UltraSonic
 Date        : 21/10/2023
 ================================================================================================
 */
#include "ultrasonic.h"
#include "lcd.h"
#include "icu.h"
#include <avr/io.h> /* To use the SREG register */


int main (void){

	uint16 Total_Distance ;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);


	/* Initialize both the LCD  */
	LCD_init();

	/* Initialize both the LCD and ICU driver */
	Ultrsonic_Init();

	LCD_displayString("Distance =    cm ");



	while(1){



		Total_Distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,11);

		if(Total_Distance < 100){

			LCD_intgerToString(Total_Distance);
			LCD_displayString(" ");

		}
		else LCD_intgerToString(Total_Distance);



	}
}
