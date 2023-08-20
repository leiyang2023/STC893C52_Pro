#include "reg52.h"

typedef unsigned int UINT32;
typedef unsigned char UINT8;

#define LED_PORT  P2     //LED管脚
#define SAMG_A_DP_PORT P0   //数码管PORT
sbit BEEP_PORT = P2^5;   //蜂鸣器管脚

void delay_10us(UINT32 time_us)
{
	while(time_us--);
}

void led_run(void)
{
	UINT8 i = 0;
	
	for(i=0;i<9;i++)
	{
		LED_PORT = ~(0x1<<i);//内部省去了寄存器写入接口，直接赋值即可；
		delay_10us(50000);
	}
}

void beep_run(void)
{
	UINT8 i = 2000;
	
	while(i > 0)
		{
			BEEP_PORT=!BEEP_PORT;
			delay_10us(50000);
			BEEP_PORT=0;
      i--;
		}
}

 /* void smg_run(void)
{
	UINT8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	UINT8 i = 0;
	
	
	while(1)
	{
		for(i=0;i<16;i++)
		{
			SAMG_A_DP_PORT = gsmg_code[i];
			delay_10us(200000);
		}
	}
						
} */

void main()
{
	led_run();
	beep_run();	
}