#include "stm32f1xx_hal.h"

#define FLASH_SPI_CS_ENABLE()                      HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_RESET)
#define FLASH_SPI_CS_DISABLE()                     HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_SET)

uint32_t SPI_FLASH_ReadID(void)
{
  uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送命令：读取芯片型号ID */
  SPI_FLASH_SendByte(W25X_JedecDeviceID);

  /* 从串行Flash读取一个字节数据 */
  Temp0 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 从串行Flash读取一个字节数据 */
  Temp1 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 从串行Flash读取一个字节数据 */
  Temp2 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 禁用串行Flash：CS高电平 */
  FLASH_SPI_CS_DISABLE();
  
  Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
  return Temp;
}

/**
  * 函数功能: 读取串行Flash设备ID
  * 输入参数: 无
  * 返 回 值: uint32_t：串行Flash的设备ID
  * 说    明：
  */
uint32_t SPI_FLASH_ReadDeviceID(void)
{
  uint32_t Temp = 0;

  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送命令：读取芯片设备ID * */
  SPI_FLASH_SendByte(W25X_DeviceID);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);
  
  /* 从串行Flash读取一个字节数据 */
  Temp = SPI_FLASH_SendByte(Dummy_Byte);

  /* 禁用串行Flash：CS高电平 */
  FLASH_SPI_CS_DISABLE();

  return Temp;
}

void flash_task()
{
	
	
}