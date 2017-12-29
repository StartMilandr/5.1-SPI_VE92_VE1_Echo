#ifndef _BRD_BTN_H
#define _BRD_BTN_H

void BRD_BTNs_Init (void);

uint32_t BRD_Is_BntAct_Select(void);
uint32_t BRD_Is_BntAct_Up    (void);
uint32_t BRD_Is_BntAct_Down  (void);
uint32_t BRD_Is_BntAct_Left  (void);
uint32_t BRD_Is_BntAct_Right (void);

uint32_t BRD_Is_BntAct_Back (void);


#endif	// _BRD_BTN_H
