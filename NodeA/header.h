typedef struct CAN1_messege{
	unsigned char rtr;
	unsigned char ff;
	unsigned char dlc;
	unsigned int id;
	unsigned int dataA;
	unsigned int dataB;
}CAN1;
extern void can1_init(void);
extern void can1_tx(CAN1 df);
extern void config_interrupts_init(void);
extern void config_vic_eints(void);
