/*--------------------------------------------------------------------
 * TITLE: M2 Hardware Definition
 * AUTHOR: Astro
 * DATE CREATED: 2017/11/1
 * FILENAME: UART0_Lin.c
 * PROJECT: M2Library
 * COPYRIGHT: Camel Microelectronics, Ltd.
 * DESCRIPTION:
 *--------------------------------------------------------------------*/
#include "UART0_Lin.h"
/**
 * @brief This function sends out Lin signal when M2's uart0 works as Master
 * 
 * @param pattern   Lin Break Pattern, NORMALBREAK or EXTREMEBREAK
 */
void RT_UART0_LinMaster(char pattern){
    RT_UART0_On();                             // UART1 on
    if(pattern) RT_UART0_LinBreakExtreme();    // pattern >=1, ExtremeBreak
    else    RT_UART0_LinBreakNormal();         // pattern ==0, NormalBreak
    RT_UART0_LinSendBreak();                   // send lin break frame
    while(RT_UART0_Busy());                    // check tx busy
    RT_UART0_Write(0x55);                      // send break syncing frame
}
