#include<lpc21xx.h>
void delay(int);

int main()
{
		int i=0;
	unsigned int num[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	//3f - 0011 1111
	PINSEL0=0X00000000;
	IO0DIR=0X000000FF;
	while(1){
		for(i=0;i<=9;i++)
		{
			IO0SET=IO0SET|num[i];
			delay(300);
			IO0CLR|=num[i];
		}
}
return 0;
}

void delay(int k)
{
    int i,j;
    for(i=0;i<k;i++)
    for(j=0;j<=1000;j++);
}
