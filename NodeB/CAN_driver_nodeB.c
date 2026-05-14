#include<lpc21xx.h>
#include"header.h"
extern CAN1 r1;
extern unsigned char flag;
#define TCS (C1GSR>>3&1)
#define RBS (C1GSR&1)
void can1_init(void)
{
	unsigned int *ptr=(unsigned int *)0xE0038000;
    PINSEL1|=0x40000; 
  PBDIV=1;
	C1MOD=1;
	AFMR=0x02;
	ptr[0]=0x05010502;
  ptr[1]=0x05030504;
	SFF_sa=0x00;
	SFF_GRP_sa=0X08;
	EFF_sa=0X08;
	EFF_GRP_sa=0X08;
	ENDofTable=0X08;
	AFMR=0X00;
	C1BTR=0x001C001D;
	C1MOD=0;	
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
	C1CMR=0x21;
	while(TCS==0);
}

void can1_rx_handler(void) __irq{
	flag=1;
	r1.id=C1RID;
	r1.dlc=(C1RFS>>16)&0xF;
	r1.rtr=(C1RFS>>30)&1;
	if(r1.rtr==0){
		r1.dataA=C1RDA;
		r1.dataB=C1RDB;
	}

	C1CMR=(1<<2);
	VICVectAddr=0;
}

void config_vic_for_can1(void){
	VICIntSelect=0;
	VICVectCntl2=26|(1<<5);
	VICVectAddr2=(unsigned int)can1_rx_handler;
	VICIntEnable=(1<<26);
	C1IER=1;
}
