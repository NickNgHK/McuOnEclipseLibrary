/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuRingbuffer.c
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
** @file McuRingbuffer.c
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup McuRingbuffer_module McuRingbuffer module documentation
**  @{
*/         

/* MODULE McuRingbuffer. */

#include "McuRingbuffer.h"

#if McuRingbuffer_CONFIG_REENTRANT
  #define McuRingbuffer_DEFINE_CRITICAL() McuCriticalSection_CriticalVariable()
  #define McuRingbuffer_ENTER_CRITICAL()  McuCriticalSection_EnterCritical()
  #define McuRingbuffer_EXIT_CRITICAL()   McuCriticalSection_ExitCritical()
#else
  #define McuRingbuffer_DEFINE_CRITICAL() /* nothing */
  #define McuRingbuffer_ENTER_CRITICAL()  /* nothing */
  #define McuRingbuffer_EXIT_CRITICAL()   /* nothing */
#endif
static McuRingbuffer_ElementType McuRingbuffer_buffer[McuRingbuffer_CONFIG_BUF_SIZE]; /* ring buffer */
static McuRingbuffer_BufSizeType McuRingbuffer_inIdx;  /* input index */
static McuRingbuffer_BufSizeType McuRingbuffer_outIdx; /* output index */
static McuRingbuffer_BufSizeType McuRingbuffer_inSize; /* size data in buffer */
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
uint8_t McuRingbuffer_Put(McuRingbuffer_ElementType elem)
{
  uint8_t res = ERR_OK;
  McuRingbuffer_DEFINE_CRITICAL();

  McuRingbuffer_ENTER_CRITICAL();
  if (McuRingbuffer_inSize==McuRingbuffer_CONFIG_BUF_SIZE) {
    res = ERR_TXFULL;
  } else {
    McuRingbuffer_buffer[McuRingbuffer_inIdx] = elem;
    McuRingbuffer_inIdx++;
    if (McuRingbuffer_inIdx==McuRingbuffer_CONFIG_BUF_SIZE) {
      McuRingbuffer_inIdx = 0;
    }
    McuRingbuffer_inSize++;
  }
  McuRingbuffer_EXIT_CRITICAL();
  return res;
}

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
uint8_t McuRingbuffer_Putn(McuRingbuffer_ElementType *elem, McuRingbuffer_BufSizeType nof)
{
  uint8_t res = ERR_OK;

  while(nof>0) {
    res = McuRingbuffer_Put(*elem);
    if (res!=ERR_OK) {
      break;
    }
    elem++; nof--;
  }
  return res;
}

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
uint8_t McuRingbuffer_Get(McuRingbuffer_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  McuRingbuffer_DEFINE_CRITICAL();

  McuRingbuffer_ENTER_CRITICAL();
  if (McuRingbuffer_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    *elemP = McuRingbuffer_buffer[McuRingbuffer_outIdx];
    McuRingbuffer_inSize--;
    McuRingbuffer_outIdx++;
    if (McuRingbuffer_outIdx==McuRingbuffer_CONFIG_BUF_SIZE) {
      McuRingbuffer_outIdx = 0;
    }
  }
  McuRingbuffer_EXIT_CRITICAL();
  return res;
}

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
McuRingbuffer_BufSizeType McuRingbuffer_NofElements(void)
{
  return McuRingbuffer_inSize;
}

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
McuRingbuffer_BufSizeType McuRingbuffer_NofFreeElements(void)
{
  return (McuRingbuffer_BufSizeType)(McuRingbuffer_CONFIG_BUF_SIZE-McuRingbuffer_inSize);
}

/*
** ===================================================================
**     Method      :  McuRingbuffer_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuRingbuffer_Init(void)
{
  McuRingbuffer_inIdx = 0;
  McuRingbuffer_outIdx = 0;
  McuRingbuffer_inSize = 0;
}

/*
** ===================================================================
**     Method      :  McuRingbuffer_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuRingbuffer_Clear(void)
{
  McuRingbuffer_DEFINE_CRITICAL();

  McuRingbuffer_ENTER_CRITICAL();
  McuRingbuffer_Init();
  McuRingbuffer_EXIT_CRITICAL();
}

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
uint8_t McuRingbuffer_Peek(McuRingbuffer_BufSizeType index, McuRingbuffer_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  int idx; /* index inside ring buffer */
  McuRingbuffer_DEFINE_CRITICAL();

  McuRingbuffer_ENTER_CRITICAL();
  if (index>=McuRingbuffer_CONFIG_BUF_SIZE) {
    res = ERR_OVERFLOW; /* asking for an element outside of ring buffer size */
  } else if (index<McuRingbuffer_inSize) {
    idx = (McuRingbuffer_outIdx+index)%McuRingbuffer_CONFIG_BUF_SIZE;
    *elemP = McuRingbuffer_buffer[idx];
  } else { /* asking for an element which does not exist */
    res = ERR_RXEMPTY;
  }
  McuRingbuffer_EXIT_CRITICAL();
  return res;
}

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
uint8_t McuRingbuffer_Compare(McuRingbuffer_BufSizeType index, McuRingbuffer_ElementType *elemP, McuRingbuffer_BufSizeType nof)
{
  uint8_t cmpResult = 0;
  uint8_t res;
  McuRingbuffer_ElementType val;

  while(nof>0) {
    res = McuRingbuffer_Peek(index, &val);
    if (res!=ERR_OK) { /* general failure? */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    if (val!=*elemP) { /* mismatch */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    elemP++; index++; nof--;
  }

  return cmpResult;
}

/*
** ===================================================================
**     Method      :  McuRingbuffer_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/**
void McuRingbuffer_Deinit(void)
{
  ** Function is implemented as macro in the header file
}
*/
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
uint8_t McuRingbuffer_Delete(void)
{
  uint8_t res = ERR_OK;
  McuRingbuffer_DEFINE_CRITICAL();

  McuRingbuffer_ENTER_CRITICAL();
  if (McuRingbuffer_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    McuRingbuffer_inSize--;
    McuRingbuffer_outIdx++;
    if (McuRingbuffer_outIdx==McuRingbuffer_CONFIG_BUF_SIZE) {
      McuRingbuffer_outIdx = 0;
    }
  }
  McuRingbuffer_EXIT_CRITICAL();
  return res;
}

/* END McuRingbuffer. */

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
