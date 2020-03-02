/**************************************************************************************************
* 文件:  txt.h
*        
* 说明:  
*        
* 作者:  rinanfang  2/29/2020
**************************************************************************************************/
#ifndef __TXT_H__
#define __TXT_H__

/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */
//FIFO num MAX = FIFO_idx+1
#define FIFO_idx_0 1

/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __TXT_C__
	#define TXT_EXT
#else
	#define TXT_EXT		extern
#endif



/*----------------------------------------------------------------------------*/
/* global stuct variable definition                                                 */
/*----------------------------------------------------------------------------*/
//MCU status
#if (0)
volatile typedef union _MCUSTATUS
{
	char  _byte;
	struct
	{
		unsigned char b_ADCdone:1;
		unsigned char b_TMAdone:1;
		unsigned char b_TMBdone:1;
		unsigned char b_TMC0done:1;
		unsigned char b_TMC1done:1;
		unsigned char b_RTCdone:1;
		unsigned char b_UART_TxDone:1;
		unsigned char b_UART_RxDone:1;
	};
} MCUSTATUS_t;
TXT_EXT MCUSTATUS_t  MCUSTATUSbits;
#endif

//device and main fuction status
#if (0)
typedef enum
{
	Auto_measurement_mode = 0,
	Man_measurement_mode,
	Disp_threshold_mode,
	password_mode,
	Setting_mode,
	Alm_mode,

} STA_WORK_list;

volatile typedef union _STATUS
{
    char _byte;
 	struct
	{
		unsigned char work;
		unsigned char work_last;
		unsigned char sw;
	};
} STATUS_t;
TXT_EXT STATUS_t sta;
#endif

//user flag
#if (0)
volatile typedef union _FLAG
{
    char _byte;
    struct
    {
		unsigned char disp_mask:1;
		unsigned char alm:1;
		unsigned char over:1;
		unsigned char beep:1;
		unsigned char change_gear:1;

    };
} FLAG_t;
TXT_EXT FLAG_t flag;
#endif

//time counter
#if (0)
volatile typedef union _TIME
{
    char _byte;
    struct
    {
		unsigned char disp_mask;
		unsigned char beep;
		unsigned short int change_gear;

    };
} TIME_t;
TXT_EXT TIME_t cnt;
#endif

//Linear storage structure fifo
#if (0)
typedef struct
{
	float bin[FIFO_idx_0+1];
	int i;
}SQ_t;
TXT_EXT SQ_t ad_fifo;
#endif

/*----------------------------------------------------------------------------*/
/* global normal variable definition                                                 */
/*----------------------------------------------------------------------------*/
//define one variable
#if (0)
TXT_EXT unsigned int Disp_threshold_cnt
#ifdef __ini_TXT_EXT_var__
=0;
#else
;
#endif
#endif


#endif



#endif  /*  __TXT_H__  */
