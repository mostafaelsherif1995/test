///*
 //* led_cf.c
 //*
 //* Created: 31/08/2016 08:24:30 م
 //*  Author: mostafa
 //*/ 
#include "LED.h"
#include "LED_Cfg.h"
const LED_ConfigType LED_ConfigParam[LED_MAX_NUM] =
{
	{ 
		PD,8,LED_ACTIVE_HIGH
		}	,
		{
			PD,7,LED_ACTIVE_HIGH
		}  ,
		{
			PD,6,LED_ACTIVE_HIGH
		},
		
		
};

