/**************************************************************************************************
* 功能:                               中断
*        
* 文件:  it.c
*        
* 说明:  
*        
* 作者:  日南方  10/13/2020
**************************************************************************************************/

#define __IT_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "txt.h"
#include <stdio.h>


/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */



/**************************************************************************************************
* 函数:                                   TIM3_Int_Init
* 说明:  
* 输入:  
*		通用定时器3中断初始化
*		这里时钟选择为APB1的2倍，而APB1为36M
*		arr：自动重装值。
*		psc：时钟预分频数
*		这里使用的是定时器3!	
* 关联变量: 
* 返回:  
* 作者:  日南方  10/14/2020
**************************************************************************************************/
void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM3, ENABLE);  //使能TIMx					 
}

/**************************************************************************************************
* 函数:                                   TIM3_IRQHandler
* 说明:   主循环的中断
* 输入:  
*		   
* 关联变量: 
* 返回:  
* 作者:  日南方  10/14/2020
**************************************************************************************************/
void TIM3_IRQHandler(void)   //TIM3中断
{

	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{
		time_ms++;
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx更新中断标志 
	}
}

