#include <REGX52.H>

void Timer0_Init()
{
	//TMOD=0x01;
	TMOD&=0xF0;
	TMOD|=0x01;
	TF0=0;
	TR0=1;
	TH0=0xFC;
	TL0=0x66;
	ET0=1;
	EA=1;
	PT0=0;
}
/*中断一秒的模板
void Timer0_Routine()   interrupt 1
{
	static unsigned int T0Count;//因为是局部变量，
	//当执行完该函数时T0Count会被清零，static是为了保证T0Count保持原有值
	TH0=0xFC;
	TL0=0x66;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

	}
}
*/