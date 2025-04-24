#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void Servo_Init(void){
	PWM_Init();
}

void Servo_SetAngle1(float angle){
	PWM_SetCompare1(angle/180*2000+500);
}
void Servo_SetAngle2(float angle){
	PWM_SetCompare2(angle/180*2000+500);
}

