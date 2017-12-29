#ifndef _BRD_DEF_VE92
#define _BRD_DEF_VE92


#ifdef USE_MDR1986VE9x

//  Buttons Definition
    #define BRD_BTN_PORT_SEL       MDR_PORTC
    #define BRD_BTN_PIN_SEL        PORT_Pin_2

    #define BRD_BTN_PORT_UP        MDR_PORTB
    #define BRD_BTN_PIN_UP         PORT_Pin_5
	
    #define BRD_BTN_PORT_RIGHT     MDR_PORTB
    #define BRD_BTN_PIN_RIGHT      PORT_Pin_6
	
    #define BRD_BTN_PORT_DOWN      MDR_PORTE
    #define BRD_BTN_PIN_DOWN       PORT_Pin_1
	
    #define BRD_BTN_PORT_LEFT      MDR_PORTE
    #define BRD_BTN_PIN_LEFT       PORT_Pin_3
	
    // for Initialization
    #define BRD_BTNs_PORT_CLK          RST_CLK_PCLK_PORTC | RST_CLK_PCLK_PORTB | RST_CLK_PCLK_PORTE

    #define BRD_BTNs_PORT_MASK         MDR_PORTC
    #define BRD_BTNs_PIN_MASK          PORT_Pin_2

    #define BRD_BTNS_DO_INIT_ext1
    #define BRD_BTNs_PORT_MASK_ext1    MDR_PORTB
    #define BRD_BTNs_PIN_MASK_ext1     PORT_Pin_5 | PORT_Pin_6

    #define BRD_BTNS_DO_INIT_ext2
    #define BRD_BTNs_PORT_MASK_ext2    MDR_PORTE
    #define BRD_BTNs_PIN_MASK_ext2     PORT_Pin_1 | PORT_Pin_3
    
    //  for Is_BtnAct_...
    #define BRD_BTNs_DO_INV    

//  LEDs Definition
    #define BRD_LED_1 	           PORT_Pin_0
    #define BRD_LED_2 	           PORT_Pin_1

    #define BRD_LED_PORT_CLK       RST_CLK_PCLK_PORTC
    #define BRD_LED_PORT           MDR_PORTC    
    #define BRD_LED_Pins           BRD_LED_1 | BRD_LED_2

//  SPI Definition
    // SPI1 PortF
	  #define BRD_SPI1_F_PIN_CLK	   PORT_Pin_1
	  #define BRD_SPI1_F_PIN_TX		   PORT_Pin_0
	  #define BRD_SPI1_F_PIN_RX		   PORT_Pin_3
	  #define BRD_SPI1_F_PIN_CS		   PORT_Pin_2    

	  #define BRD_SPI1_F_PORT_CLK    RST_CLK_PCLK_PORTF
	  #define BRD_SPI1_F_PORT			   MDR_PORTF
    #define BRD_SPI1_F_PINS        (BRD_SPI1_F_PIN_CLK | BRD_SPI1_F_PIN_TX | BRD_SPI1_F_PIN_RX | BRD_SPI1_F_PIN_CS)
    #define BRD_SPI1_F_PINS_FUNC   PORT_FUNC_ALTER
    
    #define BRD_SPI1_F_PINS_FUNC_CLEAR  (~ ((3 << (1 * 2)) | \
                                            (3 << (0 * 2)) | \
                                            (3 << (3 * 2)) | \
                                            (3 << (2 * 2)) | \
                                        ))
    
    //  SPI2 PortD
	  #define BRD_SPI2_D_PIN_CLK	   PORT_Pin_5
	  #define BRD_SPI2_D_PIN_TX		   PORT_Pin_6
	  #define BRD_SPI2_D_PIN_RX		   PORT_Pin_2
	  #define BRD_SPI2_D_PIN_CS		   PORT_Pin_3    

	  #define BRD_SPI2_D_PORT_CLK    RST_CLK_PCLK_PORTD
	  #define BRD_SPI2_D_PORT			   MDR_PORTD
    #define BRD_SPI2_D_PINS        (BRD_SPI2_D_PIN_CLK | BRD_SPI2_D_PIN_TX | BRD_SPI2_D_PIN_RX | BRD_SPI2_D_PIN_CS)
    #define BRD_SPI2_D_PINS_FUNC   PORT_FUNC_ALTER

    #define BRD_SPI2_D_PINS_FUNC_CLEAR  (~ ((3 << (5 * 2)) | \
                                            (3 << (6 * 2)) | \
                                            (3 << (2 * 2)) | \
                                            (3 << (3 * 2))   \
                                        ))

#else
   Please, select board in brdSelect.h!

#endif 


#endif // _BRD_DEF_VE92
