/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuRingbuffer.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : RingBuffer
**     Version     : Component 01.048, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-10, 10:31, # CodeGen: 86
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : McuRingbuffer
**          SDK                                            : McuLib
**          Reentrant                                      : yes
**          Critical Section                               : McuCriticalSection
**          Buffer Elements                                : 64
**          Element Size                                   : 1 Byte
**     Contents    :
**         Clear           - void McuRingbuffer_Clear(void);
**         Put             - uint8_t McuRingbuffer_Put(McuRingbuffer_ElementType elem);
**         Putn            - uint8_t McuRingbuffer_Putn(McuRingbuffer_ElementType *elem,...
**         Get             - uint8_t McuRingbuffer_Get(McuRingbuffer_ElementType *elemP);
**         Peek            - uint8_t McuRingbuffer_Peek(McuRingbuffer_BufSizeType index,...
**         Compare         - uint8_t McuRingbuffer_Compare(McuRingbuffer_BufSizeType index,...
**         Delete          - uint8_t McuRingbuffer_Delete(void);
**         NofElements     - McuRingbuffer_BufSizeType McuRingbuffer_NofElements(void);
**         NofFreeElements - McuRingbuffer_BufSizeType McuRingbuffer_NofFreeElements(void);
**         Deinit          - void McuRingbuffer_Deinit(void);
**         Init            - void McuRingbuffer_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014-2015, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file McuRingbuffer.h
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup McuRingbuffer_module McuRingbuffer module documentation
**  @{
*/         

#ifndef __McuRingbuffer_H
#define __McuRingbuffer_H

/* MODULE McuRingbuffer. */
#include "McuLib.h" /* SDK and API used */
#include "McuRingbufferconfig.h" /* configuration */

/* Include inherited components */
#include "McuLib.h"
#include "McuCriticalSection.h"


#if McuRingbuffer_CONFIG_ELEM_SIZE==1
  typedef uint8_t McuRingbuffer_ElementType; /* type of single element */
#elif McuRingbuffer_CONFIG_ELEM_SIZE==2
  typedef uint16_t McuRingbuffer_ElementType; /* type of single element */
#elif McuRingbuffer_CONFIG_ELEM_SIZE==4
  typedef uint32_t McuRingbuffer_ElementType; /* type of single element */
#else
  #error "illegal element type size in properties"
#endif
#if McuRingbuffer_CONFIG_BUF_SIZE<256
  typedef uint8_t McuRingbuffer_BufSizeType; /* up to 255 elements (index 0x00..0xff) */
#else
  typedef uint16_t McuRingbuffer_BufSizeType; /* more than 255 elements, up to 2^16 */
#endif

uint8_t McuRingbuffer_Put(McuRingbuffer_ElementType elem);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t McuRingbuffer_Get(McuRingbuffer_ElementType *elemP);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Get (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

McuRingbuffer_BufSizeType McuRingbuffer_NofElements(void);
/*
** ===================================================================
**     Method      :  McuRingbuffer_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void McuRingbuffer_Init(void);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

McuRingbuffer_BufSizeType McuRingbuffer_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  McuRingbuffer_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void McuRingbuffer_Clear(void);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuRingbuffer_Peek(McuRingbuffer_BufSizeType index, McuRingbuffer_ElementType *elemP);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Peek (component RingBuffer)
**     Description :
**         Returns an element of the buffer without removiing it.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define McuRingbuffer_Deinit() \
   /* nothing to deinitialize */
/*
** ===================================================================
**     Method      :  McuRingbuffer_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuRingbuffer_Delete(void);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Delete (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t McuRingbuffer_Putn(McuRingbuffer_ElementType *elem, McuRingbuffer_BufSizeType nof);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Putn (component RingBuffer)
**     Description :
**         Put a number new element into the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elem            - Pointer to new elements to be put into
**                           the buffer
**         nof             - number of elements
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t McuRingbuffer_Compare(McuRingbuffer_BufSizeType index, McuRingbuffer_ElementType *elemP, McuRingbuffer_BufSizeType nof);
/*
** ===================================================================
**     Method      :  McuRingbuffer_Compare (component RingBuffer)
**     Description :
**         Compares the elements in the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to elements to compare with
**         nof             - number of elements to compare
**     Returns     :
**         ---             - zero if elements are the same, -1 otherwise
** ===================================================================
*/

/* END McuRingbuffer. */

#endif
/* ifndef __McuRingbuffer_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
