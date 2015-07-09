/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        dummy.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Edgar Mosqueda
* %date_created:    Fri Feb 28 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Edgar Mosqueda   */
/* Integration under Continuus CM                                             */
/*----------------------------------------------------------------------------*/
/*  2.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Edgar Mosqueda   */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef struct{
	T_UWORD  ruw_Counter;
	T_UWORD  ruw_TopCount;
	tCallbackFunction   cpfu_PerFunct;
}TASKSTRUCT;

typedef enum 
{
	e_dummy_1,
	e_dummy_2,
	e_dummy_3,
	e_dummy_4
	
}e_dummy;

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */

void dummy_500us(void);
void dummy_endless_loop(void);
void Task_10ms(void);

/* Functions macros */


/* Exported defines */



#endif /* _DUMMY_H */

/*******************************************************************************/
