/*
 * i2c_app.c
 *
 *  Created on: Dec 3, 2024
 *  Author: moshte
 */

#include "i2c_app.h"
#define BUFFERSIZE 20

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c1)
{
	 HAL_I2C_EnableListen_IT(hi2c1);
}


void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c1, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	uint8_t RxData[BUFFERSIZE];
	//uint8_t TxData[16] ={5,3,1,9,9,5,4,1,8,3,2,8,4,0,4,7};
	char msg[100] = {"hello from stm"};

	    if(TransferDirection == I2C_DIRECTION_TRANSMIT)
		{
			HAL_I2C_Slave_Sequential_Receive_IT(hi2c1, RxData, 30, I2C_FIRST_AND_LAST_FRAME);
			//HAL_Delay(100);
		}
		else if(TransferDirection == I2C_DIRECTION_RECEIVE)
		{
			HAL_I2C_Slave_Sequential_Transmit_IT(hi2c1, (uint8_t *)msg, 16, I2C_FIRST_AND_LAST_FRAME);
			//HAL_Delay(100);
		}
		else
		{
			Error_Handler();
		}

}
