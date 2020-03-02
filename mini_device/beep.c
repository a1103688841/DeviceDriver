/**************************************************************************************************
* 功能:                              beep
*        
* 文件:  beep.c
*        
* 说明:  
*        
* 作者:  日南方  2/29/2020
**************************************************************************************************/

#define __BEEP_C__
/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

/*----------------------------------------------------------------------------*/
/* Function Name: Beep_Tone_Start                                             */
/* Description  : Start PWM beep tone.                                        */
/* Arguments    : None.                                                       */
/* Return Value : None.                                                       */
/* Remark       :                                                             */
/*----------------------------------------------------------------------------*/
void Beep_Tone_Start(void)
{
	Beep_Tone_Cnt = BEEP_TONE_TIME;
	DrvTMB_Open( E_TMB_MODE0, E_TMB_NORMAL, PWM_4KHZ_TIME );        //set TMB working on normal mode & TMB clock int period= PWM_4KHZ_TIME/HS_CK= 250uS.
	DrvPWM0_Open( 0, 1, 2 );                                        //Set PT2.0= PWMO0, PT2.1= PWMO1 and PWMO0 working on PWMA mdoe with normal pulse output.
	DrvPWM1_Open( 0, 0, 2 );                                        //Set PT2.0= PWMO0, PT2.1= PWMO1 and PWMO1 working on PWMA mdoe with reverse pulse output.
}

/*----------------------------------------------------------------------------*/
/* Function Name: Beep_Tone_Stop                                              */
/* Description  : Stop PWM beep tone.                                         */
/* Arguments    : None.                                                       */
/* Return Value : None.                                                       */
/* Remark       :                                                             */
/*----------------------------------------------------------------------------*/
void Beep_Tone_Stop(void)
{
	Beep_Tone_Cnt = 0;
	DrvTMB_Close();
	DrvPWM0_Close();
	DrvPWM1_Close();
	DrvGPIO_ClrPortBits( E_PT2, 0x03 );         //set PT2[1:0] as output low.
}


/*----------------------------------------------------------------------------*/
/* Function Name: Beep_Tone_Process                                           */
/* Description  : Beep tone time processing.                                  */
/* Arguments    : None.                                                       */
/* Return Value : None.                                                       */
/* Remark       :                                                             */
/*----------------------------------------------------------------------------*/
void Beep_Tone_Process(void)
{
	if (Beep_Tone_Cnt != 0)
	{
		Beep_Tone_Cnt--;
		if (Beep_Tone_Cnt <= 0)
			Beep_Tone_Stop();
	}
}


