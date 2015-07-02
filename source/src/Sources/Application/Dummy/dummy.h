

/*******************************************************************************/
/**
\file       dummy.h
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/*******************************************************************************/

#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/

void dummy_500us(void);
void dummy_endless_loop(void);
void Task_100ms(void);
void delay(void);
void manual_mode(void);
void anti_pinch(void);
void auto_up(void);
void delay_pinch(void);

typedef struct{
	T_UWORD  ruw_Counter;
	T_UWORD  ruw_TopCount;
	tCallbackFunction   cpfu_PerFunct;
}TASKSTRUCT;



 enum dummy
{
	e_dummy_1,
	e_dummy_2,
	e_dummy_1_2,
	e_dummy_2_2
};



#endif /* _DUMMY_H */

/*******************************************************************************/
