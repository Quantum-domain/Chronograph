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
/*�ж�һ���ģ��
void Timer0_Routine()   interrupt 1
{
	static unsigned int T0Count;//��Ϊ�Ǿֲ�������
	//��ִ����ú���ʱT0Count�ᱻ���㣬static��Ϊ�˱�֤T0Count����ԭ��ֵ
	TH0=0xFC;
	TL0=0x66;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

	}
}
*/