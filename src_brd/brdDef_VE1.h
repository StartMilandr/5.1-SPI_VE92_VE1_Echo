#ifndef _BRD_DEF_VE1
#define _BRD_DEF_VE1

#ifdef USE_MDR1986VE1T

//  Buttons Definition
    #define BRD_BTN_PORT_SEL       MDR_PORTE
    #define BRD_BTN_PIN_SEL        PORT_Pin_9

    #define BRD_BTN_PORT_UP        MDR_PORTE
    #define BRD_BTN_PIN_UP         PORT_Pin_8
	
    #define BRD_BTN_PORT_RIGHT     MDR_PORTE
    #define BRD_BTN_PIN_RIGHT      PORT_Pin_5
	
    #define BRD_BTN_PORT_DOWN      MDR_PORTE
    #define BRD_BTN_PIN_DOWN       PORT_Pin_15
	
    #define BRD_BTN_PORT_LEFT      MDR_PORTE
    #define BRD_BTN_PIN_LEFT       PORT_Pin_10
	
    #define BRD_BTN_PORT_BACK      MDR_PORTE
    #define BRD_BTN_PIN_BACK       PORT_Pin_11	

    // for Initialization
    #define BRD_BTNs_PORT_CLK      RST_CLK_PCLK_PORTE
    #define BRD_BTNs_PORT_MASK     MDR_PORTE
    #define BRD_BTNs_PIN_MASK      BRD_BTN_PIN_SEL | BRD_BTN_PIN_UP | BRD_BTN_PIN_RIGHT | BRD_BTN_PIN_DOWN | BRD_BTN_PIN_LEFT | BRD_BTN_PIN_BACK
    
    //  for Is_BtnAct_...
    #define BRD_BTNs_DO_INV


//  LEDs Definition
    #define BRD_LED_PORT_CLK       RST_CLK_PCLK_PORTD
    #define BRD_LED_PORT           MDR_PORTD
  
    #define BRD_LED_1              PORT_Pin_7
    #define BRD_LED_2              PORT_Pin_8
    #define BRD_LED_3              PORT_Pin_9
    #define BRD_LED_4              PORT_Pin_10	
  
    #define BRD_LED_Pins (BRD_LED_1 | BRD_LED_2 | BRD_LED_3 | BRD_LED_4)

//  SPI Definition
	  #define BRD_SPI1_D_PIN_CLK	PORT_Pin_4
	  #define BRD_SPI1_D_PIN_TX		PORT_Pin_2
	  #define BRD_SPI1_D_PIN_RX		PORT_Pin_3
	  #define BRD_SPI1_D_PIN_CS		PORT_Pin_5    

	  #define BRD_SPI1_D_PORT_CLK    RST_CLK_PCLK_PORTD
	  #define BRD_SPI1_D_PORT			   MDR_PORTD
    #define BRD_SPI1_D_PINS        (BRD_SPI1_D_PIN_CLK | BRD_SPI1_D_PIN_TX | BRD_SPI1_D_PIN_RX | BRD_SPI1_D_PIN_CS)
    #define BRD_SPI1_D_PINS_FUNC   PORT_FUNC_ALTER
    
    #define BRD_SPI1_D_PINS_FUNC_CLEAR  (~ ((3 << (4 * 2)) | \
                                            (3 << (2 * 2)) | \
                                            (3 << (3 * 2)) | \
                                            (3 << (5 * 2))   \
                                        ))

#else
   Please, select board in brdSelect.h!

#endif    

#endif // _BRD_DEF_VE1
