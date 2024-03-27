#include "UART_Transmit.h"

void uart_display(unsigned char* ptr,UART_HandleTypeDef* huart)
{
	unsigned int size=0; 
	unsigned char* str;
	str=ptr;
	
	while(*str!='\0')
	{
		size++;
		str++;
	}
	
	if(HAL_UART_Transmit_IT(huart, ptr , size)!= HAL_OK)
	{
		Error_Handler();
		}
}


