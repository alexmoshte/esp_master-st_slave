/*
 * i2c_app.h
 *
 *  Created on: Dec 3, 2024
 *  Author: moshte
 */

#ifndef INC_I2C_APP_H_
#define INC_I2C_APP_H_

#include "stm32f4xx_hal.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

extern void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c1);
extern void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c1, uint8_t TransferDirection, uint16_t AddrMatchCode);

#endif /* INC_I2C_APP_H_ */
