/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         dummy.C
* Instance:         RPL_1
* %version:         2 %
* %created_by:      Edgar Mosqueda
* %date_created:    Fri Jan  9 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : Window lifter                                                */
/*============================================================================*/
/* FUNCTION COMMENT : Window lifter is the module responsible to control the  */
/*                    window movement.                                        */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 30/06/2015  |                               | Edgar Mosqueda   */
/* Integration under Continuus CM                                             */
/*============================================================================*/


/*******************************************************************************
* Include files
********************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "dummy.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */
TASKSTRUCT *rps_TaskPtr;



/********************************************************************************
* Definition of module wide VARIABLEs 
*********************************************************************************/
T_UBYTE rub_cnt=0;
T_UBYTE rub_flag_2;
T_UBYTE rub_flag;
T_UBYTE rub_TOP_COUNT=11;
/*********************************************************************************
* Declaration of module wide FUNCTIONs 
**********************************************************************************/
void delay(void);
void manual_mode(void);
void anti_pinch(void);
void auto_up(void);
void delay_pinch(void);
/**********************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
***********************************************************************************/

/**********************************************************************************
* Declaration of module wide TYPEs 
***********************************************************************************/

/**********************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
***********************************************************************************/

/***********************************************************************************
* Code of module wide FUNCTIONS
************************************************************************************/


/****************************************************************************************************/


void Task_100ms(void)

{

static T_UWORD lub_U16Counter = 0;
static T_UWORD lub_U16Counter_1 = 0;
    
    lub_U16Counter++;
    lub_U16Counter_1++;
    
   if(lub_U16Counter_1==rub_TOP_COUNT)
   {
   	lub_U16Counter_1=0;
   }
  
   if(lub_U16Counter==rub_TOP_COUNT)
   {
   	lub_U16Counter=0;
   }
    

if(PUSH_PRESSED(P3_PUSH) )
{

LED_OFF(LED_DOWN);
LED_OFF(LED_UP);
anti_pinch();
rub_flag=e_dummy_1;


}

if( PUSH_PRESSED(P2_DOWN) && PUSH_PRESSED(P1_UP) )
		{
		
		}
		
		
		if( PUSH_PRESSED(P1_UP) && lub_U16Counter_1==5 ) 
    {
    	
    		lub_U16Counter_1=0;
    		rub_flag_2=e_dummy_1_2;
    		LED_ON(LED_UP);
    		LED_OFF(LED_DOWN);	
			rub_cnt--;
    		manual_mode();
    
    }
		
if( PUSH_PRESSED(P1_UP) && lub_U16Counter_1==10 )
    {
    
    
    	LED_ON(LED_UP);
    	LED_OFF(LED_DOWN);	
    	auto_up();
		rub_flag_2=e_dummy_2_2;	
    
    	
    		
		}
		

	

		
if( PUSH_PRESSED(P2_DOWN) && lub_U16Counter==10 )
    {
    	lub_U16Counter=0;
    	LED_ON(LED_DOWN);
    	LED_OFF(LED_UP);	
    	anti_pinch();
		rub_flag=e_dummy_1;
    	
    		
    		
		}
if( PUSH_PRESSED(P2_DOWN) && lub_U16Counter==5 )
    {
    	
    	
    	rub_flag=e_dummy_2;
    	LED_ON(LED_DOWN);
    	LED_OFF(LED_UP);	
    	rub_cnt++;
    	manual_mode();
    		
    		
		}
	
			
	}
    		



TASKSTRUCT function_table_def[]={

	{ 0, 20,/*200*/    &Task_100ms },
//	{ 0, 50,    &Task_10ms },

};


void dummy_500us(void)
{
	static T_UBYTE i=0;
	for(i = 0; i < 1; i++)
	{
		(rps_TaskPtr+i)->ruw_Counter++;
		if( (rps_TaskPtr+i)->ruw_Counter == (rps_TaskPtr+i)->ruw_TopCount   )
		{
			(rps_TaskPtr+i)->cpfu_PerFunct();
			(rps_TaskPtr+i)->ruw_Counter = 0;
		}
	}
}




void dummy_endless_loop(void)
{
	rps_TaskPtr = function_table_def;
	for(;;)
	{
	}
	
}



void anti_pinch(void)
{
while(rub_flag==e_dummy_1){


		
	switch(rub_cnt)
	{
		case 1:
		
			LED_OFF(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	
			LED_OFF(LED1);
    		delay();
    		rub_cnt=2;
    		break;
    	case 2:
    	
    	LED_ON(LED1);
			
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	
			LED_OFF(LED2);
    
    		delay();
    		rub_cnt=3;
    	break;
    	case 3:
	LED_ON(LED1);
			LED_ON(LED2);
    		
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		LED_OFF(LED3);
    	
    		delay();
    		rub_cnt=4;
    	break;
    	case 4:
		
		LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    	
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		LED_OFF(LED4);
		
    		delay();
    		rub_cnt=5;
    	break;
    	case 5:
    	LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	
			LED_OFF(LED5);
    		
    		delay();
    		rub_cnt=6;
    	break;
    	case 6:
	LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		LED_OFF(LED6);
    	
    		delay();
    		rub_cnt=7;
    	break;
    	case 7:	
		
		LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		LED_OFF(LED7);
		
    		delay();
    		rub_cnt=8;
    	break;
    	case 8:
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_OFF(LED9);
    		LED_OFF(LED10);
			LED_OFF(LED8);
    	
    		delay();
    		rub_cnt=9;
    	break;
    	case 9:
    		LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		
    		
    	
    		delay();
    		rub_cnt=10;
    	break;
    	case 10:
    		LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    		LED_OFF(LED10);
    		rub_cnt=11;
    		delay();
    		break;
    	case 11:
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    		LED_ON(LED10);
    		rub_flag=e_dummy_2;
    		rub_cnt=11;
    		
    	delay();
    break;
    	
	}
	

}


}

void auto_up(void)
{
while(rub_flag_2==e_dummy_1_2){
	
	
switch(rub_cnt)
	{
		case 11:
		
			if(PUSH_PRESSED(P3_PUSH) )
			{

			LED_OFF(LED_DOWN);
			LED_OFF(LED_UP);
			anti_pinch();
			rub_flag=e_dummy_1;
			delay_pinch();

			}
			else
			{/*
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    		LED_ON(LED10);*/
		
    		delay();
    		rub_cnt=10;	
			}
			
    		break;
    	case 10:
    	
    		if(PUSH_PRESSED(P3_PUSH) )
			{

			LED_OFF(LED_DOWN);
			LED_OFF(LED_UP);
			anti_pinch();
			rub_flag=e_dummy_1;
			delay_pinch();
			}
			else
			{/*
			LED_ON(LED1);
    		LED_ON(LED2);
			LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    	LED_OFF(LED1);*/
			delay();
    		rub_cnt=9;	
			}
    		
    	break;
    	case 9:
    	
    	if(PUSH_PRESSED(P3_PUSH) )
			{

			LED_OFF(LED_DOWN);
			LED_OFF(LED_UP);
			anti_pinch();
			rub_flag=e_dummy_1;
			delay_pinch();
			}
			
			else
			{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    	LED_OFF(LED9);
    	LED_OFF(LED10);
    		delay();
    		rub_cnt=8;	
			}
			
    	break;
    	case 8:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();
			}
			else
			{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
		LED_OFF(LED8);
    	LED_OFF(LED9);
    	LED_OFF(LED10);	
    		delay();
    		rub_cnt=7;
			}
			
    		
		
    		
    	break;
    	case 7:
    	
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();
			}
			else
			{
		LED_ON(LED1);
		LED_ON(LED2);
    	LED_ON(LED3);
    	LED_ON(LED4);
    	LED_ON(LED5);
		LED_ON(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		delay();
    		rub_cnt=6;	
			}
    	
    	break;
    	case 6:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
delay_pinch();
			}
			else
			{
			LED_ON(LED1);
		LED_ON(LED2);
    	LED_ON(LED3);
    	LED_ON(LED4);
		LED_ON(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		delay();
    		rub_cnt=5;	
			}
		
    	break;
    	case 5:	
		if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();

			}
			else
			{
			LED_ON(LED1);
		LED_ON(LED2);
    	LED_ON(LED3);
    	LED_ON(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		delay();
    		rub_cnt=4;	
			}
		
    	break;
    	case 4:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();

			}
			else
			{
			LED_ON(LED1);
		LED_ON(LED2);
    	LED_ON(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
			delay();
    		rub_cnt=3;	
			}
		
    	break;
    	case 3:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();

			}
			else
			{
				LED_OFF(LED3);
		LED_OFF(LED4);
    	LED_OFF(LED5);
    	LED_OFF(LED6);
		LED_OFF(LED7);
    	LED_OFF(LED8);
    	LED_OFF(LED9);
		LED_OFF(LED10);
    		LED_ON(LED1);
    		LED_ON(LED2);
    	
    		delay();
    		rub_cnt=2;	
			}
    
    	break;
    	case 2:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();

			}
			else
			{
			LED_OFF(LED10);
			LED_OFF(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    	LED_ON(LED1);
    		rub_cnt=1;
    		delay();	
			}
    		
    		break;
    	case 1:
    	if(PUSH_PRESSED(P3_PUSH) )
			{

				LED_OFF(LED_DOWN);
				LED_OFF(LED_UP);
				anti_pinch();
				rub_flag=e_dummy_1;
				delay_pinch();

			}
			else
			{
			LED_OFF(LED1);
			LED_OFF(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
    		rub_flag_2=e_dummy_2_2;
    		rub_cnt=1;
    		delay();	
			}
			
    break;
    	

	}
}

}

void manual_mode(void)
{
if(rub_cnt==1)
	{
			LED_OFF(LED1);
			LED_OFF(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}

		if(rub_cnt==2)
	{
			LED_ON(LED1);
			LED_OFF(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		
		if(rub_cnt==3)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_OFF(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==4)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_OFF(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}		
	
		if(rub_cnt==5)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_OFF(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
	
		if(rub_cnt==6)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_OFF(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==7)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_OFF(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==8)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_OFF(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==9)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_OFF(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==10)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    		LED_OFF(LED10);
	}
		if(rub_cnt==11)
	{
			LED_ON(LED1);
			LED_ON(LED2);
    		LED_ON(LED3);
    		LED_ON(LED4);
			LED_ON(LED5);
    		LED_ON(LED6);
    		LED_ON(LED7);
			LED_ON(LED8);
    		LED_ON(LED9);
    		LED_ON(LED10);
    		
	}
}

void delay(void)
{
/*	static T_UWORD delay_Counter = 0;
	
	delay_Counter++;
	
	if(delay_Counter==8000000)
	{
		delay_Counter=0;
	}*/
	static T_ULONG j,k;
	for(j=1;j<=500;j++)
	{
		for(k=1; k<=10000; k++)
		{
			
		}
	}
	
}
void delay_pinch(void)
{
/*	static T_UWORD delay_Counter = 0;
	
	delay_Counter++;
	
	if(delay_Counter==800)
	{
		delay_Counter=0;
	}*/
	static T_ULONG j,k;//REVISAR ESTO
	for(j=1;j<=500;j++)
	{
		for(k=1; k<=100000; k++)
		{
			
		}
	}
	
}

