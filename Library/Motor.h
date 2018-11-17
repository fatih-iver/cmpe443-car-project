#ifndef MOTOR_H
#define MOTOR_H

#include "LPC407x_8x_177x_8x.h"
#include "SystemStructures.h"
#include "PWM.h"
#include "GPIO.h"

// PWM FOR MOTORS
// DEFINING THE FUNCTIONALITIES IN IOCONS
#define IOCON_PWM0_1_ADDRESS 0x4002C08C
#define IOCON_PWM0_1 *((volatile uint32_t *) IOCON_PWM0_1_ADDRESS)

#define IOCON_PWM0_2_ADDRESS 0x4002C088
#define IOCON_PWM0_2 *((volatile uint32_t *) IOCON_PWM0_2_ADDRESS)

#define IOCON_PWM0_6_ADDRESS 0x4002C0AC
#define IOCON_PWM0_6 *((volatile uint32_t *) IOCON_PWM0_6_ADDRESS)


// IN1 PIN
#define IN1_PORT PORT1
#define IN1_MASK ((uint32_t) 1 << 24)

// IN2 PIN
#define IN2_PORT PORT1
#define IN2_MASK ((uint32_t) 1 << 23)

// IN3 PIN
#define IN3_PORT PORT1
#define IN3_MASK ((uint32_t) 1 << 20)

// IN4 PIN
#define IN4_PORT PORT0
#define IN4_MASK ((uint32_t) 1 << 21)

typedef enum {
	FORWARD  = 2,
	BACKWARD  = 1,
	STOP = 0
} Motor_Direction;


void Motor_Init(void);
void Motor_PWM_Init(void);
void Motor_Direction_Init(void);
void Motor_Handle(int direction, GPIO_TypeDef *MOTOR1, uint32_t MASK1, GPIO_TypeDef *MOTOR2, uint32_t MASK2);
void Motor_Controller(int motor1, int motor2, int speed);

#endif