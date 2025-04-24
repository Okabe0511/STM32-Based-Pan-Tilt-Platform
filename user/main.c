#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "servo.h"
#include "KEY.h"
#include "OLED.h"
#include "Timer.h"
uint16_t i,Knum = 0,num1 = 0,num2 = 0,flag=0;
int value1 = 2,value2 = 3;
char sv1[5][7]={"state1","state2","state3","state4"};
char sv2[7][7]={"left2 ","left1 ","center","right1","right2","-     "};
int main(void)
{
	Timer_Init();
	OLED_Init();
	Servo_Init();
	KEY_Init();
	OLED_ShowString(1,1,"servo1:");
	OLED_ShowString(3,1,"servo2:");
	while(1){
		OLED_ShowString(2,1,sv1[value1-3]);
		if(value1<=6){
		Servo_SetAngle1(value1*30);
		}
		else if(value1>6){
		value1 = 3;
}
		OLED_ShowString(4,1,sv2[value2-1]);
		if(value2<=6&&value2>0){
		Servo_SetAngle2((value2*30)-7);
		}
		else if(value2>6){
		value2 = 3;
}
		else if(value2==0){value2 = 3;}
	}

}
void TIM4_IRQHandler(void){
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) == SET)
	{
		Knum = Key_GetNum();
		if(Knum == 1){
		num1++;
		}
		if(Knum==2){
		num2++;
		flag=0;
		}
		if(Knum==3){
		num2--;
		flag=1;
		}
		if(num1>=15&&Knum==0){
			value1++;
			num1=0;
		}
		if(num2>=15&&Knum==0){
			if(flag==0){
			value2++;
			num2=0;
			}
			else if(flag==1){
			value2--;
			num2=0;
			}
		}
		
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	}
}
