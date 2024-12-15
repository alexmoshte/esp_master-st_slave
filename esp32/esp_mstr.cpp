#include "esp_mstr.h"


//WRITING STRING TO SLAVE
int Write_Strng(String cntnt)
{
    /*Writing to the slave*/
  Wire.beginTransmission(I2C_DEV_ADDR);
  const char* char_Arr = cntnt.c_str(); // Converts cntnt to a char array
  Wire.write(char_Arr);
  Wire.write(i);
  uint8_t error = Wire.endTransmission(true);
  //Serial.printf("endTransmisssion: %u\n", error);

  if (error == 0)
  {
    Serial.printf("Write succesfull: moshte %u\n", i);
    i++;
    return 1;
  }
  else
  {
    Serial.printf("Write failure!\n");
    return 0;
  }
}

//READING 16 BYTES FROM SLAVE
String Read_bytes(void)
{
  uint8_t bytesReceived = Wire.requestFrom(I2C_DEV_ADDR, 16); //Requesting data from the slave 
  Serial.printf ("requestFrom: %u\n", bytesReceived);


  if (bytesReceived > 0)
  {
    //uint8_t RxData[bytesReceived];
    char RxData[bytesReceived];
    for (uint8_t i =0; i < bytesReceived; i++)
    {
      RxData[i]=Wire.read();
    }
     
    Serial.println("Read successfull");
    Serial.println("Received Data:\n");

    for (uint8_t i=0; i< bytesReceived; i++)
    {
      Serial.printf("%c", RxData[i]);
    }
    
    String str = String(RxData);
    return str;

  }
  else
  {
    Serial.println("Read failure!\n");
    return;
  }
}

//INITIALIZE I2C
void I2C_Init(void)
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  //Wire.begin();
  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(SCL_FRQNCY);
  //delay(5000);
  Serial.println("I2C successfully initialized!");
}