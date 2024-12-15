#include <Arduino.h>
#include "Wire.h"

#define I2C_DEV_ADDR 0x12
#define I2C_NUM I2C_NUM_0
#define I2C_SCL GPIO_NUM_22
#define I2C_SDA GPIO_NUM_21
#define SCL_FRQNCY 100000

uint32_t i=0;

//FUNCTION DECLARATIONS
void I2C_Init(void);
String Read_bytes(void);
int Write_Strng(String cntnt);