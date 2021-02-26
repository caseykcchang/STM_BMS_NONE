#include "stm32f1xx_hal.h"

#define FLASH_SPI_CS_ENABLE()                      HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_RESET)
#define FLASH_SPI_CS_DISABLE()                     HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_SET)

uint32_t SPI_FLASH_ReadID(void)
{
  uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

  /* ѡ����FLASH: CS�͵�ƽ */
  FLASH_SPI_CS_ENABLE();

  /* ���������ȡоƬ�ͺ�ID */
  SPI_FLASH_SendByte(W25X_JedecDeviceID);

  /* �Ӵ���Flash��ȡһ���ֽ����� */
  Temp0 = SPI_FLASH_SendByte(Dummy_Byte);

  /* �Ӵ���Flash��ȡһ���ֽ����� */
  Temp1 = SPI_FLASH_SendByte(Dummy_Byte);

  /* �Ӵ���Flash��ȡһ���ֽ����� */
  Temp2 = SPI_FLASH_SendByte(Dummy_Byte);

  /* ���ô���Flash��CS�ߵ�ƽ */
  FLASH_SPI_CS_DISABLE();
  
  Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
  return Temp;
}

/**
  * ��������: ��ȡ����Flash�豸ID
  * �������: ��
  * �� �� ֵ: uint32_t������Flash���豸ID
  * ˵    ����
  */
uint32_t SPI_FLASH_ReadDeviceID(void)
{
  uint32_t Temp = 0;

  /* ѡ����FLASH: CS�͵�ƽ */
  FLASH_SPI_CS_ENABLE();

  /* ���������ȡоƬ�豸ID * */
  SPI_FLASH_SendByte(W25X_DeviceID);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);
  
  /* �Ӵ���Flash��ȡһ���ֽ����� */
  Temp = SPI_FLASH_SendByte(Dummy_Byte);

  /* ���ô���Flash��CS�ߵ�ƽ */
  FLASH_SPI_CS_DISABLE();

  return Temp;
}

void flash_task()
{
	
	
}