/*
 * motorsdriver.h
 *
 *  Created on: Feb 18, 2024
 *      Author: Simeon Tornabene
 */

#ifndef SRC_MOTORSDRIVER_MOTORSDRIVER_H_
#define SRC_MOTORSDRIVER_MOTORSDRIVER_H_

#include "stm32g071xx.h"

#define TIM1_PRESCALER 				16 - 1
#define ARR_VAL			 			20000
#define MOTOR_ESC_IGNITION_PULSE_US 800
#define MOTOR_IGNITION_PULSE_US 	1100
#define MOTOR_THROTTLE_MAX_PULSE_US	2000

class MotorsDriver {
public:
	MotorsDriver();
	virtual ~MotorsDriver();

public:
	enum MotorChannel {
		FRONT_LEFT = 0,
		FRONT_RIGTH,
		BACK_LEFT,
		BACK_RIGTH
	};

private:
	/**
	  * @brief  Initialize TIM1 and Motor's GPIO for PWM mode
	  * @param  None
	  * @retval None
	  */
	void init();

public:
	/**
	  * @brief
	  * @param  motorsChannel ESC motor to power on
	  * @retval None
	  */
	void escIngnition(MotorChannel motorsChannel);

	/**
	  * @brief
	  * @param  motorsChannel motor to power on
	  * @retval None
	  */
	void motorIgnition(MotorChannel motorsChannel);

	/**
	  * @brief
	  * @param  motorsChannel motor to power off
	  * @retval None
	  */
	void motorPowerOff(MotorChannel motorsChannel);

	/**
	  * @brief
	  * @param  motorsChannel motor to manage
	  * @param 	pulseWidthUs duty cycle is us
	  * @retval None
	  */
	void motorThrottle(MotorChannel motorsChannel, uint16_t pulseWidthUs);
};

#endif /* SRC_MOTORSDRIVER_MOTORSDRIVER_H_ */
