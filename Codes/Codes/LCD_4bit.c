#include "LCD_4bit.h"

void cmd(char c)
{
		int temp=0x00;
		int val;

		HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_RESET);
		
		//MSB Transfer
		val=LCD_D7_GPIO_Port->IDR;
		//LCD_D7_GPIO_Port->ODR=val;
	
		temp=0x00;
		temp=c&0xF0;
		temp=temp>>4;
		if(LCD_D7_Pin>8)
			temp=temp*(LCD_D7_Pin/8);
		
		val=val&(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin));
		val=val|(temp&(~(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin))));
		
		LCD_D7_GPIO_Port->ODR=val;
	
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_RESET);
		HAL_Delay(10);		

		//LSB Transfer
		val=LCD_D7_GPIO_Port->IDR;

		temp=0x00;
		temp=c&0x0F;
		//temp=temp>>4;
		
	
		temp=temp*(LCD_D7_Pin/8);
		val=val&(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin));
		val=val|(temp&(~(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin))));
	
		LCD_D7_GPIO_Port->ODR=val;
	
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_RESET);
		HAL_Delay(10);		
		
}

void dat(char d)
{
		int temp=0x00;
		int val;

		HAL_GPIO_WritePin(LCD_RS_GPIO_Port,LCD_RS_Pin,GPIO_PIN_SET);
		//MSB Transfer
		val=LCD_D7_GPIO_Port->IDR;
		
		temp=0x00;
		temp=d&0xF0;
		temp=temp>>4;
	
		temp=temp*(LCD_D7_Pin/8);
		val=val&(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin));
		val=val|(temp&(~(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin))));
		
		LCD_D7_GPIO_Port->ODR=val;
	
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_RESET);
		HAL_Delay(10);		
		
		//LSB Transfer
		val=LCD_D7_GPIO_Port->IDR;

		temp=0x00;
		temp=d&0x0F;
		//temp=temp>>4;
	
		temp=temp*(LCD_D7_Pin/8);
		val=val&(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin));
		val=val|(temp&(~(0xFFFFFFFF^(LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin))));
		
		LCD_D7_GPIO_Port->ODR=val;
	
		
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,GPIO_PIN_RESET);
		HAL_Delay(10);		
		
}

void string_dat(char *str)
{
	while(*str!='\0')
	{
		dat(*str);
		str++;
	}
}

void blanks_dat(char count)
{
	while(count>0)
	{
		dat(' ');
		count--;
	}
}

void number_dat(int num)
{
	char num_dat[10],i=0,j=0;
	char temp[10];

	while(num>0)
	{
		temp[i]=(num%10)+48;
		num/=10;
		i++;
	}

	while(i>0)
	{
		num_dat[j]=temp[i-1];
		j++;
		i--;
	}
	num_dat[j]='\0';
	
	string_dat(num_dat);	
	
}


void initialize()
{
		cmd(0x33);
		cmd(0x32);
		cmd(0x28);
		cmd(0x01);
		cmd(0x0E);
}

