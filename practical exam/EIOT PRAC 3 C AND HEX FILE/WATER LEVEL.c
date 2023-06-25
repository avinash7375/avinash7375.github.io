#include<reg51.h>
#define lcdport P2
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

sbit half=P1^0;
sbit full=P1^2;
sbit mid=P1^1;
sbit buzzer=P3^6;

void lcdcmd(char);
void lcdint();
void lcddata(char);
void lcdstring(char *);
void delay(unsigned int);

void main()
{
	P1=0x00;
	half=full=mid=0;
	buzzer=0;
	
	 while(1)
	 {
		 lcdint();
		 if(half==0&&full==0&&mid==0)
	  {  
		  lcdcmd(0x85);
		  lcdstring("EMPTY");
	  }	 
	 	 if(half==1&&full==0&&mid==0)
	  { 
		 lcdcmd(0x85);
		 lcdstring("low");
	  }	 
	  if(half==1&&full==0&&mid==1)
	  { 
		 lcdcmd(0x85);
		 lcdstring("HALF");
	  }	
    
	  if(half==1&&full==1&&mid==1)
		{
			buzzer=1;
			lcdcmd(0x85);
			lcdstring("FULL !!!");
			lcdcmd(0xc3);
			lcdstring("MOTOR OFF");
			buzzer=0;
		}
	 }
}

    void delay(unsigned int x )
		{
			unsigned int i;
			for(i=0;i<x;i++);
		}
		
		void lcdint()
		{
			lcdcmd(0x38);
			delay(500);
			lcdcmd(0x01);
			delay(500);
			lcdcmd(0x0c);
			delay(500);
			lcdcmd(0x80);
			delay(500);
			lcdcmd(0x0e);
			delay(500);
		}
		
		void lcdcmd(char value)
		{
			lcdport = value;
			rw=0;
			rs=0;
			en=1;
			delay(500);
			en=0;
			}
		
			void lcdstring(char *p)
			{
				while(*p!='\0')
				{
					lcddata(*p);
					delay(10000);
					p++;
				}
			}
			
			void lcddata(char value)
			{
				lcdport = value;
				rs=1;
				rw=0;
				en=1;
				delay(500);
				en=0;
			}
		