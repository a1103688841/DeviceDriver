/**************************************************************************************************
* ����:                              base function
*        
* �ļ�:  ybase.c
*        
* ˵��:  
*        
* ����:  rinanfang  2/29/2020
**************************************************************************************************/

#define __YBASE_C__
/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

void cycle(uint8_t *min, uint8_t *max, uint8_t *current)
{
	current++;
	if (current>max)
	{
		current=min;
	}
}
