/*******************************************************************************/
/**
\file       GPIO.c
\brief      General purpose IO functions
\author     Abraham Tezmol
\version    1.0
\date       31/10/2008
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */


/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain)
{
    if (input_output == GPIO_OUTPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.OBE = 1;					/* Output buffer enable */
    	if (Open_drain == GPIO_OPEN_DRAIN_ENABLE)
    	{
    		SIU.PCR[channel].B.ODE = 1;				/* Open drain option enable */	
    	}
    	else
    	{	
    		SIU.PCR[channel].B.ODE = 0;				/* Push-pull option enable */	
    	}
    }
    else if (input_output == GPIO_INPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.IBE = 1;					/* Input buffer enable */	
    }

}

/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value)
{
    SIU.GPDO[channel].B.PDO  = logical_value;  		/* Drive the logical output value to the pin */

}

void vfnGPIO_Input(uint8_t channel, uint8_t logical_value)
{
    SIU.GPDI[channel].B.PDI  = logical_value;  		/* Drive the logical input value to the pin */

}



/****************************************************************************************************/
/**
* \brief    Turn a combination of 3 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
void vfnGPIO_FlashMainLED(void)
{
    static uint8_t u8Counter = 0;
    
    u8Counter++;
    switch (u8Counter)
    {
    case  1:
            LED_ON(LED1);
            LED_ON(LED2);
            break;
    case  11:
            LED_ON(LED3);
            LED_ON(LED4);                     
            break;
    case  21:
            LED_ON(LED2);
            LED_ON(LED3);                     
            break;        
    case  3:
            LED_OFF(LED1);
            LED_OFF(LED2);
            break;
    case  13:
            LED_OFF(LED3);
            LED_OFF(LED4);
            break;                          
    case  23:
            LED_OFF(LED2);
            LED_OFF(LED3);
            break;        
	case 100:
		u8Counter = 0;
		break;
    }
}


/****************************************************************************************************/
/**
* \brief    Initialize GPIO port connected to LEDs on eval board
* \author   Abraham Tezmol
* \param    void 
* \return   void
*/
void vfnGPIO_LED_Init(void)
{

	/*toggle dummy*/
	vfnGPIO_Init_channel(LED_dummy,GPIO_OUTPUT,GPIO_OPEN_DRAIN_ENABLE);    /* PE4 --> LED_UP*/
	vfnGPIO_Output (LED_dummy, 1);

    /* Data Port A initialization */
	vfnGPIO_Init_channel(LED_UP,GPIO_OUTPUT,GPIO_OPEN_DRAIN_ENABLE);    /* PE4 --> LED_UP*/
	vfnGPIO_Output (LED_UP, 1);
	vfnGPIO_Init_channel(LED_DOWN,GPIO_OUTPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE5 --> LED_DOWN*/
	vfnGPIO_Output (LED_DOWN, 1);
	/**/
	vfnGPIO_Init_channel(LED1,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE4 --> LED1*/
	vfnGPIO_Output (LED1, 1);
	vfnGPIO_Init_channel(LED2,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE5 --> LED2*/
	vfnGPIO_Output (LED2, 1);
	vfnGPIO_Init_channel(LED3,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE6 --> LED3*/
	vfnGPIO_Output (LED3, 1);
	vfnGPIO_Init_channel(LED4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE7 --> LED4*/
	vfnGPIO_Output (LED4, 1);
	vfnGPIO_Init_channel(LED5,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE4 --> LED5*/
	vfnGPIO_Output (LED5, 1);
	vfnGPIO_Init_channel(LED6,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE5 --> LED6*/
	vfnGPIO_Output (LED6, 1);
	vfnGPIO_Init_channel(LED7,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE6 --> LED7*/
	vfnGPIO_Output (LED7, 1);
	vfnGPIO_Init_channel(LED8,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE7 --> LED8*/
	vfnGPIO_Output (LED8, 1);
	vfnGPIO_Init_channel(LED9,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE6 --> LED9*/
	vfnGPIO_Output (LED9, 1);
	vfnGPIO_Init_channel(LED10,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE7 --> LED10*/
	vfnGPIO_Output (LED10, 1);

	
}

/****************************************************************************************************/
/**
* \brief    Initialize GPIO port connected to Pushs on eval board
* \author   Mario Rivera
* \param    void 
* \return   void
*/

void vfnGPIO_PUSH_Init(void)
{
	vfnGPIO_Init_channel(P1_UP,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);
	vfnGPIO_Input(P1_UP, 1);
	vfnGPIO_Init_channel(P2_DOWN,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);
	vfnGPIO_Input(P2_DOWN, 1);
	vfnGPIO_Init_channel(P3_PUSH,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);
	vfnGPIO_Input(P3_PUSH, 1);
	//vfnGPIO_Init_channel(P1_PUSH,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);	
	//vfnGPIO_Input(P4_PUSH, 1);
	
}