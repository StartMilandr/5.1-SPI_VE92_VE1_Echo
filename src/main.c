#include "brdClock.h"
#include "brdBtn.h"
#include "brdLed.h"
#include "brdUtils.h"
#include "brdSPI.h"

#include "brdDef.h"
#include "brdSPI_Select.h"

#if defined (USE_BOARD_VE_1)
  #define MASTER_MODE 0   
#elif defined (USE_BOARD_VE_92)
  #define MASTER_MODE 1  
#endif


#define LED_CYCLE          BRD_LED_1
#define LED_ERR            BRD_LED_2
#define LED_SWITCH_PERIOD  40000     // In SPI transfers


#define  TEST_VALUE_MAX  0xFF

uint16_t rdValue;
uint16_t wrValue;
uint16_t prevValue;

//  Counters
uint16_t rdCount;
uint16_t errCount;

//  Test Function
void Master_SPI_Transfer(void);
void Slave_SPI_Transfer(void);

uint16_t IncData(uint16_t value);

#define WITHOUT_FSS   1

int main(void)
{
  //  Ожидание, чтобы при одновременной подаче питания ведомый уже был готов, к моменту старта мастера
#ifdef MASTER_MODE
  Delay(20000);
#endif
  
  
  // Clock
  BRD_Clock_Init_HSE_PLL(RST_CLK_CPU_PLLmul10); // 80MHz
  
  //  Controls
  BRD_BTNs_Init();
  BRD_LEDs_Init();
  rdCount = 0;
  errCount = 0;
   
  //  SPI PINS Init
  BRD_SPI_PortInit(pBRD_SPIx);  
#if !MASTER_MODE
  //  Подтяжка CLK к 0 для ведомого, чтобы не ловил случайные помехи, пока мастер не подключился к линии.
  MDR_PORTD->PULL = BRD_SPI1_D_PIN_CLK;
#endif
  
  //  SPI Init
#if WITHOUT_FSS
  pBRD_SPIx->pSSPInitStruct->SSP_SPH = SSP_SPH_2Edge;
#endif
#if !MASTER_MODE
  //  Max sampling rate for slave!
  pBRD_SPIx->pSSPInitStruct->SSP_CPSDVSR = 12;
  pBRD_SPIx->pSSPInitStruct->SSP_SCR = 0;
#endif
  
  BRD_SPI_Init(pBRD_SPIx, MASTER_MODE);  
 
  // Write and read Ack
  while (1)
  {  
#if MASTER_MODE
      Master_SPI_Transfer();
#else
      Slave_SPI_Transfer();
#endif      
  }
}

void Master_SPI_Transfer()
{
  uint16_t nextWrValue = IncData(wrValue);
  
  //  Transfer
  rdValue = BRD_SPI_Master_WRRD(pBRD_SPIx, nextWrValue);
    
  //  Count Transfers and Errors
  ++rdCount;
  if (rdValue != wrValue)
    ++errCount;
  
  wrValue = nextWrValue;
  
  //  Show status to LED
  if (rdCount > LED_SWITCH_PERIOD) 
  {      
    //  Show processing
    BRD_LED_Switch(LED_CYCLE);
    
    //  Show Error Status   
    if (errCount != 0)
      BRD_LED_Switch(LED_ERR);
    else
      BRD_LED_Set(LED_ERR, 0);
    
    rdCount = 0;
    errCount = 0;
  }
}  

void Slave_SPI_Transfer()
{ 
  if (BRD_SPI_CanRead(pBRD_SPIx))
  {
    //  Echo
    rdValue = BRD_SPI_ReadValue(pBRD_SPIx);
    BRD_SPI_Slave_SendNext(pBRD_SPIx, rdValue);
    
    //  Count Transfers and Errors
    ++rdCount;
    if (rdValue != IncData(prevValue))
      ++errCount;
    
    prevValue = rdValue;
    
    //  Show status to LED
    if (rdCount > LED_SWITCH_PERIOD) 
    {      
      //  Show processing
      BRD_LED_Switch(LED_CYCLE);
      
      //  Show Error Status   
      if (errCount != 0)
        BRD_LED_Switch(LED_ERR);
      else
        BRD_LED_Set(LED_ERR, 0);
      
      rdCount = 0;
      errCount = 0;
    }
    
  }   
} 

uint16_t IncData(uint16_t value)
{
  value++;
  if (value > TEST_VALUE_MAX)
    value = 0;
  
  return value;
}
