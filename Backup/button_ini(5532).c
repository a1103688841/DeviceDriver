/************************************************************
	* @brief   button_ini
 ***********************************************************/
#define	__button_var__
#include "button_ini.h"

/*******************************************************************
 *                         call function
 *******************************************************************/
static void 		SW0_Down_CallBack(void *btn);
static void 		SW1_Down_CallBack(void *btn);
static void 		SW2_Down_CallBack(void *btn);
static void 		SW3_Down_CallBack(void *btn);
static unsigned char 	Read_SW0_Level	(void);
static unsigned char 	Read_SW1_Level	(void);
static unsigned char 	Read_SW2_Level	(void);
static unsigned char 	Read_SW3_Level	(void);
/************************************************************
	* @brief   call button down fuction
	* @param   btn :
	* @param   STA :
	* @return  NULL
	* @author  rinanfang
	* @github  
	* @date    2019-12-13
	* @version v1.0
	* @note    NULL
  ***********************************************************/
static void SW0_Down_CallBack(void *btn)
{
	switch(sta.sys)
	{
		case Auto_measurement_mode:
			sta.sys_last=Auto_measurement_mode;
			sta.sys=Man_measurement_mode;
			break;
		case Man_measurement_mode:
			sta.sys_last=Man_measurement_mode;
			sta.sys=Auto_measurement_mode;
			break;
		case password_mode:
			if(password==password_key)
			{
				sta.sys=Setting_mode;
				Flash_i=Flash_1;
				Alarm_threshold_i=Alarm_threshold_f*10;
				if(Alarm_threshold_f>0)
				{
					num[4]=seg_Positive;
				}else{
					num[4]=seg_negative;
					Alarm_threshold_i=Alarm_threshold_i*-1;
				}
				num[0]=Alarm_threshold_i%10;
				num[1]=Alarm_threshold_i/10%10;
				num[2]=Alarm_threshold_i/100%10;
				num[3]=Alarm_threshold_i/1000%10;
			}else{
				sta.sys=sta.sys_last;
			}
			break;
		case Setting_mode:
			sta.sys=sta.sys_last;
			Alarm_threshold_i=num[0]+num[1]*10+num[2]*100+num[3]*1000;
			if(num[4]==seg_negative)
			{
				Alarm_threshold_i=Alarm_threshold_i*-1;
			}
			Alarm_threshold_f=Alarm_threshold_i*0.1;
			break;
	}

}
//“<”键：

static void SW1_Down_CallBack(void *btn)
{
	if(!GetSW2)
	{

		switch(sta.sys)
		{
			//Man_measurement_mode and Auto_measurement_mode have same process;
			case Auto_measurement_mode:
			sta.sys_last=Auto_measurement_mode;
			case Man_measurement_mode:
				sta.sys=Man_measurement_mode;
				Measurement_gear_next--;
				if(Measurement_gear_next==Min_gear)
				{
					Measurement_gear_next=Max_gear;
					Measurement_gear_next--;
				}
				flag.change_gear=TRUE;
				flag.change_gear_cnt=0;
				//ad_fifo.i=0;
				break;
			case Setting_mode:
				if(Flash_i==4)
				{
					if(num[4]==seg_negative)
					{
						num[4]=0;
					}else{
						num[4]=seg_negative;
					}
				}else{

					if(num[4]==0)
					{
						num[4]=seg_Positive;
					}
					num[Flash_i]++;
					if(num[Flash_i]>9)
					{
						num[Flash_i]=0;
					}
				}
				break;
			case password_mode:
				num[Flash_i]++;
				if(num[Flash_i]>9)
				{
					num[Flash_i]=0;
				}
				password=num[0]+num[1]*10+num[2]*100+num[3]*1000+num[4]*10000;
				break;
		}
	}
}
//“>”键：
void SW2_Down_CallBack(void *btn)
{

	if(!GetSW1)
	{
		switch(sta.sys)
		{
			//Man_measurement_mode and Auto_measurement_mode have same process;
			case Auto_measurement_mode:
				sta.sys_last=Auto_measurement_mode;
			case Man_measurement_mode:
				sta.sys=Man_measurement_mode;
				Measurement_gear_next++;
				if(Measurement_gear_next==Max_gear)
				{
					Measurement_gear_next=Min_gear;
					Measurement_gear_next++;
				}
				flag.change_gear=TRUE;
				flag.change_gear_cnt=0;
				break;
			case password_mode:
			case Setting_mode:
				Flash_i++;
				if(Flash_i==Flash_max)
				{
					Flash_i=Flash_1;
				}
				if(Flash_i==4)
				{
					if(num[4]==seg_Positive)
					{
						num[4]=0;
					}
				}else{
					if(num[4]==0)
					{
						num[4]=seg_Positive;
					}
				}
				break;
		}
	}
}
void SW3_Down_CallBack(void *btn)
{
	switch(sta.sys)
	{
		case Alm_mode:
		flag.alm_single=BUTTON_FALSE;
		sta.sys=sta.sys_last;
		break;
	}
}
void SW1_2_Down_CallBack(void *btn)
{
	switch(sta.sys)
	{
	//Man_measurement_mode and Auto_measurement_mode have same process;
	case Auto_measurement_mode:
		sta.sys_last=Auto_measurement_mode;
		sta.sys=Disp_threshold_mode;
		break;
	case Man_measurement_mode:
		sta.sys_last=Man_measurement_mode;
		sta.sys=Disp_threshold_mode;
		break;
	}
	Alarm_threshold_i=Alarm_threshold_f*10;
	if(Alarm_threshold_f>0)
	{
		num[4]=seg_Positive;
	}else{
		num[4]=seg_negative;
		Alarm_threshold_i=Alarm_threshold_i*-1;
	}
	num[0]=Alarm_threshold_i%10;
	num[1]=Alarm_threshold_i/10%10;
	num[2]=Alarm_threshold_i/100%10;
	num[3]=Alarm_threshold_i/1000%10;
}
/************************************************************
* @brief   call button Long fuction
* @param   btn :
***********************************************************/
void SW1_2_Long_CallBack(void *btn)
{

	switch(sta.sys)
	{
	//Man_measurement_mode and Auto_measurement_mode have same process;
		case Auto_measurement_mode:
			sta.sys_last=Auto_measurement_mode;
			sta.sys=password_mode;
			Flash_i=Flash_1;
		break;
		case Man_measurement_mode:
			sta.sys_last=Man_measurement_mode;
			sta.sys=password_mode;
			Flash_i=Flash_1;
		break;
	}
	password=0;
}

/************************************************************
	* @brief   read one button level
	* @return  unsigned char :TURE FALSE
	* @author
	* @github  
	* @date    2019-12-13
	* @version v1.0
	* @note    NULL
  ***********************************************************/
static unsigned char Read_SW0_Level(void)
{
	if(GetSW0)
	{
		return BUTTON_INI_TRUE;
	}
	else
	{
		return BUTTON_INI_FALSE;
	}
}
static unsigned char Read_SW1_Level(void)
{
	if(GetSW1)
	{
		if(GetSW2)
		{
			return BUTTON_INI_FALSE;
		}else
		{
			return BUTTON_INI_TRUE;
		}
	}
	else
	{
		return BUTTON_INI_FALSE;
	}
}
static unsigned char Read_SW2_Level(void)
{
	if(GetSW2)
	{
		if(GetSW1)
		{
			return BUTTON_INI_FALSE;
		}else
		{
			return BUTTON_INI_TRUE;
		}
	}
	else
	{
		return BUTTON_INI_FALSE;
	}
}
static unsigned char Read_SW3_Level(void)
{
	if(GetSW3)
	{
		return BUTTON_INI_TRUE;
	}
	else
	{
		return BUTTON_INI_FALSE;
	}
}
static unsigned char Read_SW1_2_Level(void)
{
	if(GetSW1&&GetSW2)
	{
		return BUTTON_INI_TRUE;
	}
	else
	{
		return BUTTON_INI_FALSE;
	}
}
/************************************************************
	* @brief   read multity button level
	* @return  unsigned char :TURE FALSE
	* @author
	* @github
	* @date    2019-12-13
	* @version v1.0
	* @note    NULL
  ***********************************************************/
/************************************************************
	* @brief   button attach
	* @param   void
	* @return  void
	* @author
	* @github
	* @date    2019-12-13
	* @version v1.0
	* @note    NULL
  ***********************************************************/
void Button_Attach_ini(void)
{
  Button_Create("SW0",
              &SW0,
              Read_SW0_Level,
              HIGHT);
 Button_Attach(&SW0,BUTTON_DOWM,SW0_Down_CallBack);                       //call fuction attach


  Button_Create("SW1",
              &SW1,
              Read_SW1_Level,
              HIGHT);
Button_Attach(&SW1,BUTTON_DOWM,SW1_Down_CallBack);                     //

  Button_Create("SW2",
              &SW2,
              Read_SW2_Level,
              HIGHT);
 Button_Attach(&SW2,BUTTON_DOWM,SW2_Down_CallBack);                     //

  Button_Create("SW3",
              &SW3,
              Read_SW3_Level,
              HIGHT);
  Button_Attach(&SW3,BUTTON_DOWM,SW3_Down_CallBack);                    //
 
  Button_Create("SW1&SW2",
              &SW1_2,
              Read_SW1_2_Level,
              HIGHT);
  Button_Attach(&SW1_2,BUTTON_DOWM,SW1_2_Down_CallBack);                    //
  Button_Attach(&SW1_2,BUTTON_LONG,SW1_2_Long_CallBack);                    //
}
