#include<lpc21xx.h>
#include"header.h"
extern CAN1 msg1,msg2,msg3;
extern unsigned char headlight_flag,Left_indicator_flag,Right_indicator_flag;
#define TCS (C1GSR>>3&1)
void can1_init(void)
{
  PINSEL1|=0x40000; //P0.25 RD1 PIN
	VPBDIV=1; //60MHZ
	C1MOD=1;//RESET MODE
	AFMR=2;
	C1BTR=0x001C001D;//Baud is 125Kbps
	C1MOD=0;//cancel reset mode	
	}
void can1_tx(CAN1 df)
{
	C1TID1=df.id;
	C1TFI1=(df.dlc<<16)|(df.rtr<<30)|(df.ff<<31);
	if(df.rtr==0)
	{
	C1TDA1=df.dataA;
	C1TDB1=df.dataB;
	}
	C1CMR=0x21;//Start Xmission &//select Txbuf1 for Xmission
	while(TCS==0);
}
