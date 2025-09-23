#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Hour,Min,Sec;
unsigned int Mil;
bit isRunning=0;

void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Clock: ");
	LCD_ShowString(2,1,"  :  :  :");
	while(1)
	{
		if(P3_1==0){Delay(10);isRunning=0;while(P3_1==0);isRunning=1;}//��ʼ
		if(P3_0==0){Delay(10);isRunning=0;while(P3_0==0);}//��ͣ
		if(P3_2==0){Delay(10);Mil=0;Sec=0;Min=0;Hour=0;while(P3_2==0);}//��λ
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
		LCD_ShowNum(2,10,Mil,4);//�����Ŀ
	}
}

void Timer0_Routine()   interrupt 1
{
	//��Ϊ�Ǿֲ�������
	//��ִ����ú���ʱT0Count�ᱻ���㣬static��Ϊ�˱�֤T0Count����ԭ��ֵ
	TH0=0xFC;
	TL0=0x66;
	if(isRunning)
	{
	Mil++;
	if(Mil>=1000)
	{
		Mil=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
				if(Min>=60)
				{
				Min=0;
				Hour++;
				if(Hour>=24)
					Hour=0;
				}
			}
		}
	}
}