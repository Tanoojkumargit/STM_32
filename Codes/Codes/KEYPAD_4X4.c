#include "KEYPAD_4X4.h"

void colput(int col)
{
		int temp=0;

		temp=KEYPAD_C1_GPIO_Port->IDR;
	
		if(KEYPAD_C4_Pin>8)
			col=col*(KEYPAD_C4_Pin/8);
		
		temp=temp&(0XFFFFFFFF^(KEYPAD_C1_Pin|KEYPAD_C2_Pin|KEYPAD_C3_Pin|KEYPAD_C4_Pin));
	//	KEYPAD_C1_GPIO_Port->ODR=temp;
		temp=temp|(col&(KEYPAD_C1_Pin|KEYPAD_C2_Pin|KEYPAD_C3_Pin|KEYPAD_C4_Pin));
		KEYPAD_C1_GPIO_Port->ODR=temp;
	}

char keypad_try(char *preset)
{
//	HAL_GPIO_WritePin(GPIOC,col_1_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOC,col_2_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOC,col_3_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOC,col_4_Pin,GPIO_PIN_RESET);
	while(!(*preset))
	{
		colput(0x01);
		if(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET);
			return 1;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET);
		return 5;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET);
		return 9;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET);
		return 13;
		}

		colput(0x02);
		if(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET);
			return 2;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET);
		return 6;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET);
		return 10;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET);
		return 14;
		}

		
		colput(0x04);
		if(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET);
			return 3;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET);
		return 7;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET);
		return 11;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET);
		return 15;
		}

		colput(0x08);
		if(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R1_GPIO_Port,KEYPAD_R1_Pin)==SET);
			return 4;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R2_GPIO_Port,KEYPAD_R2_Pin)==SET);
		return 8;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R3_GPIO_Port,KEYPAD_R3_Pin)==SET);
		return 12;
		}
		else 	if(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET)
		{
		while(HAL_GPIO_ReadPin(KEYPAD_R4_GPIO_Port,KEYPAD_R4_Pin)==SET);
		return 16;
		}

	}
}