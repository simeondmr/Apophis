/*
 * motorsdriver.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: Simeon Tornabene
 */

#include <MotorsDriver/motorsdriver.h>

MotorsDriver::MotorsDriver()
{
	this->init();
}

MotorsDriver::~MotorsDriver()
{

}

void MotorsDriver::init()
{
	RCC->APBENR2 |= RCC_APBENR2_TIM1EN_Msk;
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN_Msk;
	GPIOA->MODER &= ~(GPIO_MODER_MODE8_Msk | GPIO_MODER_MODE9_Msk | GPIO_MODER_MODE10_Msk | GPIO_MODER_MODE11_Msk);
	GPIOA->MODER |= (GPIO_MODER_MODE8_1 | GPIO_MODER_MODE9_1 | GPIO_MODER_MODE10_1 | GPIO_MODER_MODE11_1);
	GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED8_1 | GPIO_OSPEEDR_OSPEED9_1 | GPIO_OSPEEDR_OSPEED10_1 | GPIO_OSPEEDR_OSPEED11_1);
	GPIOA->AFR[1] |= (GPIO_AFRH_AFSEL8_1 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL11_1);
	TIM1->ARR = ARR_VAL;
	TIM1->PSC = TIM1_PRESCALER;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC1PE_Msk | TIM_CCMR1_OC2PE_Msk;
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC3PE_Msk | TIM_CCMR2_OC4PE_Msk;
	TIM1->BDTR |= TIM_BDTR_MOE_Msk;
	TIM1->CR1 |= TIM_CR1_ARPE_Msk;
	TIM1->EGR = TIM_EGR_UG_Msk;
	TIM1->CCER |= TIM_CCER_CC1E_Msk | TIM_CCER_CC2E_Msk | TIM_CCER_CC3E_Msk | TIM_CCER_CC4E_Msk;
	TIM1->CR1 |= TIM_CR1_CEN_Msk;
}

void MotorsDriver::escIngnition(MotorChannel motorChannel)
{
	this->motorThrottle(motorChannel, MOTOR_ESC_IGNITION_PULSE_US);
}

void MotorsDriver::motorIgnition(MotorChannel motorChannel)
{
	this->motorThrottle(motorChannel, MOTOR_IGNITION_PULSE_US);
}

void MotorsDriver::motorPowerOff(MotorChannel motorChannel)
{
	this->motorThrottle(motorChannel, MOTOR_ESC_IGNITION_PULSE_US);
}

void MotorsDriver::motorThrottle(MotorChannel motorChannel, uint16_t pulseWidthUs)
{
	switch (motorChannel) {
	case FRONT_LEFT:
		TIM1->CCR1 = pulseWidthUs;
		break;
	case FRONT_RIGTH:
		TIM1->CCR2 = pulseWidthUs;
		break;
	case BACK_LEFT:
		TIM1->CCR3 = pulseWidthUs;
		break;
	case BACK_RIGTH:
		TIM1->CCR4 = pulseWidthUs;
		break;
	}
}
