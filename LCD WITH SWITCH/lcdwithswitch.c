#include<lpc214x.h>
#define bit(x) (1<<x)
#define delay for(i=0;i<3000;i++);
/*
P0.0 - P0.7 : D0 - D7
P0.8 - RS
P0.9 - RW
P0.10 - EN
*/
unsigned int i;
void lcd_int();
void dat(unsigned char);
void cmd(unsigned char);
void string(unsigned char *);
void main()
{
/* IO0DIR|=0XFFF;
lcd_int();
cmd(0x8a);
string("EMBETRONICX.COM ");
while(1) {
cmd(0x18);
delay;*/
PINSEL0=0x00000000;
IO0DIR|=0X000007FF;
int sum,mul;
sum = 30+2;
mul = 3*3;
char character[2];
character[0] = (sum/10)+'0';
character[1] = (sum%10) + '0';
char character1 = mul+'0';
lcd_int();
cmd(0x80);
if((IO0PIN & 0x0000800) == 0x00000800)
{
cmd(0x80);
string(" Sum is = ");
dat(character[0]);
dat(character[1]);
}
else
{
cmd(0xC0);
string(" Product is = ");
dat(character1);
}
}
void lcd_int()
{
cmd(0x38);
cmd(0x0c);
cmd(0x06);
cmd(0x01);
cmd(0x80);
}
void cmd(unsigned char a)
{
IO0PIN&=0x00;
IO0PIN|=(a<<0);
IO0CLR|=bit(8); //rs=0
IO0CLR|=bit(9); //rw=0
IO0SET|=bit(10); //en=1
delay;
IO0CLR|=bit(10); //en=0
}
void dat(unsigned char b)
{
IO0PIN&=0x00;
IO0PIN|=(b<<0);
IO0SET|=bit(8); //rs=1
IO0CLR|=bit(9); //rw=0
IO0SET|=bit(10); //en=1
delay;
IO0CLR|=bit(10); //en=0
}
void string(unsigned char *p)
{
while(*p!='\0') {
dat(*p++);
}
}

