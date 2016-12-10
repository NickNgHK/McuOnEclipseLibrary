/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuPercepio.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : PercepioTrace
**     Version     : Component 01.075, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-10, 10:31, # CodeGen: 86
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuPercepio
**          RTOS+Trace Version                             : V3.0.2
**          SDK                                            : McuLib
**          Streaming with RTT                             : Disabled
**          Utility                                        : McuUtility
**          Scheduling only                                : no
**          Description string                             : FreeRTOS+Trace
**          Description max length                         : 80
**          Events                                         : 
**            Kernel Service Calls                         : 
**              Task                                       : 
**                vTaskDelay                               : yes
**                vTaskDelayUntil                          : yes
**          Include user events                            : yes
**          Include ISR tracing                            : yes
**          Max ISR Nesting                                : 16
**          Include object delete events                   : yes
**          Include new time events                        : no
**          Include ready events                           : yes
**          Include memory manager events                  : no
**          Heap Size below 16M                            : no
**          Trace Data Allocation                          : static
**          Recorder store mode                            : Ring Buffer
**          Use implicit IFE rules                         : yes
**          Use 16bit Object Handles                       : no
**          Include event stats                            : no
**          Event Count Size                               : 256
**          Float support                                  : no
**          Event buffer size                              : 1200
**          Symbol table size                              : 400
**          Number of tasks                                : 10
**          Number of ISR                                  : 4
**          Number of queue                                : 3
**          Number of semaphore                            : 4
**          Number of mutex                                : 4
**          Number of Timer                                : 2
**          Number of Event Groups                         : 2
**          Name length for task                           : configMAX_TASK_NAME_LEN
**          Name length for ISR                            : 10
**          Name length for queue                          : 15
**          Name length for semaphore                      : 15
**          Name length for mutex                          : 15
**          Name length for timer                          : 15
**          Name length for event group                    : 15
**     Contents    :
**         uiTraceStart                                - dword McuPercepio_uiTraceStart(void);
**         vTraceStop                                  - void McuPercepio_vTraceStop(void);
**         vTraceClear                                 - void McuPercepio_vTraceClear(void);
**         uiTraceGetTraceBufferSize                   - dword McuPercepio_uiTraceGetTraceBufferSize(void);
**         vTraceGetTraceBuffer                        - void* McuPercepio_vTraceGetTraceBuffer(void);
**         vTraceSetTimerFrequency                     - void McuPercepio_vTraceSetTimerFrequency(dword frequency);
**         xTraceOpenLabel                             - traceLabel McuPercepio_xTraceOpenLabel(char *label);
**         vTraceUserEvent                             - void McuPercepio_vTraceUserEvent(traceLabel eventLabel);
**         vTracePrintF                                - void McuPercepio_vTracePrintF(traceLabel eventLabel, char *formatStr, ...);
**         vTraceSetQueueName                          - void McuPercepio_vTraceSetQueueName(void *queue, char *name);
**         vTraceSetISRProperties                      - void McuPercepio_vTraceSetISRProperties(objectHandleType handle, char *name,...
**         vTraceStoreISRBegin                         - void McuPercepio_vTraceStoreISRBegin(objectHandleType id);
**         vTraceStoreISREnd                           - void McuPercepio_vTraceStoreISREnd(int pendingISR);
**         vTraceTaskSkipDefaultInstanceFinishedEvents - void McuPercepio_vTraceTaskSkipDefaultInstanceFinishedEvents(void);
**         vTraceTaskInstanceIsFinished                - void McuPercepio_vTraceTaskInstanceIsFinished(void);
**         vTraceExcludeTaskFromSchedulingTrace        - void McuPercepio_vTraceExcludeTaskFromSchedulingTrace(const char* name);
**         vTraceInitTraceData                         - void* McuPercepio_vTraceInitTraceData(void);
**         vGetGDBDumpCommand                          - void McuPercepio_vGetGDBDumpCommand(uint8_t *buf, uint16_t bufSize, uint8_t...
**         vTraceSetStopHook                           - void McuPercepio_vTraceSetStopHook(TRACE_STOP_HOOK stopHookFunction);
**         xTraceGetLastError                          - char* McuPercepio_xTraceGetLastError(void);
**         vTraceClearError                            - byte McuPercepio_vTraceClearError(int resetErrorMessage);
**         vTraceTaskInstanceFinish                    - void McuPercepio_vTraceTaskInstanceFinish(void);
**         vTraceTaskInstanceFinishDirect              - void McuPercepio_vTraceTaskInstanceFinishDirect(void);
**
**     * (c) Copyright Percepio AB, 2013-2016
**     * http      : www.percepio.se
**     * mail      : info@percepio.com
**      * See separate Percepio licensing terms.
**      *
**      * Processor Expert Component: (c) Copyright Erich Styger, 2013-2016
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuPercepio.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuPercepio_module McuPercepio module documentation
**  @{
*/         

#ifndef __McuPercepio_HvTraceInitTraceData
#define __McuPercepio_H

/* MODULE McuPercepio. */
#include "McuLib.h" /* SDK and API used */
#include "McuPercepioconfig.h" /* configuration */

/* Include inherited components */
#include "McuLib.h"
#include "McuUtility.h"

#if McuLib_CONFIG_SDK_VERSION_USED != McuLib_CONFIG_SDK_PROCESSOR_EXPERT
  /* prototypes for user events */
  void McuPercepio_OnTraceWrap(void);
#endif

#include "trcUser.h" /* traditional recorder, without streaming over RTT */


#define McuPercepio_uiTraceGetTraceBufferSize() \
  uiTraceGetTraceBufferSize()

/*
** ===================================================================
**     Method      :  McuPercepio_uiTraceGetTraceBufferSize (component PercepioTrace)
**     Description :
**         Gets the size of the recorder data structure. For use
**         together with vTraceGetTraceBuffer if you wish to implement
**         an own store/upload solution, e.g., in case a debugger
**         connection is not available for uploading the data.
**     Parameters  : None
**     Returns     :
**         ---             - Size of the trace buffer
** ===================================================================
*/

#define McuPercepio_vTraceGetTraceBuffer() \
  vTraceGetTraceBuffer()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceGetTraceBuffer (component PercepioTrace)
**     Description :
**         Return a pointer to the recorder data structure. Use this
**         together with uiTraceGetTraceBufferSize if you wish to
**         implement an own store/upload solution, e.g., in case a
**         debugger connection is not available for uploading the data.
**     Parameters  : None
**     Returns     :
**         ---             - Pointer to the trace buffer
** ===================================================================
*/

#define McuPercepio_vTraceSetTimerFrequency(frequency) \
  vTraceSetTimerFrequency(frequency)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceSetTimerFrequency (component PercepioTrace)
**     Description :
**         Use this to define the frequency of the timer/counter used
**         for timestamping (in Hz)
**     Parameters  :
**         NAME            - DESCRIPTION
**         frequency       - frequency
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_uiTraceStart() \
  uiTraceStart()
/*
** ===================================================================
**     Method      :  McuPercepio_uiTraceStart (component PercepioTrace)
**     Description :
**         Starts the trace.
**     Parameters  : None
**     Returns     :
**         ---             - returns 1 if trace has been started, 0
**                           otherwise.
** ===================================================================
*/

#define McuPercepio_vTraceStop() \
  vTraceStop()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceStop (component PercepioTrace)
**     Description :
**         Stops the trace.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceClear() \
  vTraceClear()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceClear (component PercepioTrace)
**     Description :
**         Clears the trace.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_xTraceOpenLabel(label) \
  xTraceOpenLabel(label)

/*
** ===================================================================
**     Method      :  McuPercepio_xTraceOpenLabel (component PercepioTrace)
**     Description :
**         Open/create symbol to use as user event handle for related
**         user events (conceptually like a file handle)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * label           - Pointer to label
**     Returns     :
**         ---             - trace label
** ===================================================================
*/

#define McuPercepio_vTraceUserEvent(eventLabel) \
  vTraceUserEvent(eventLabel)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceUserEvent (component PercepioTrace)
**     Description :
**         Simple user event - store a label, created using
**         xTraceOpenLabel
**     Parameters  :
**         NAME            - DESCRIPTION
**         eventLabel      - trace label for the user
**                           event
**     Returns     : Nothing
** ===================================================================
*/

/* void McuPercepio_vTracePrintF(traceLabel eventLabel, char *formatStr, ...); */
#define McuPercepio_vTracePrintF vTracePrintF

/*
** ===================================================================
**     Method      :  McuPercepio_vTracePrintF (component PercepioTrace)
**     Description :
**         Advanced user event - like printf (but limited formatting
**         support - will improve)
**     Parameters  :
**         NAME            - DESCRIPTION
**         eventLabel      - trace label
**       * formatStr       - Pointer to format string
**         Variable_1      - open parameter list
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceSetQueueName(queue, name) \
  vTraceSetQueueName(queue, name)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceSetQueueName (component PercepioTrace)
**     Description :
**         Assigns a name to a FreeRTOS Queue, Semaphore or Mutex. This
**         function should  be called right after creation of the
**         queue/mutex/semaphore. If not using this function, the
**         queues/mutexes/semaphores will be presented by their numeric
**         handle only.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * queue           - Pointer to the queue
**       * name            - Pointer to name
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceSetISRProperties(handle, name, prioritiy) \
  vTraceSetISRProperties(handle, name, prioritiy)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceSetISRProperties (component PercepioTrace)
**     Description :
**         Registers an Interrupt Service Routine in the recorder
**         library, This must be called before using
**         vTraceStoreISRBegin to store ISR events. This is typically
**         called in the startup of the system, before the scheduler is
**         started. Method is always enabled if 'Include ISR tracing'
**         is set to 'yes' in the properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - handle to be used
**       * name            - Pointer to name
**         prioritiy       - priority
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceStoreISRBegin(id) \
  vTraceStoreISRBegin(id)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceStoreISRBegin (component PercepioTrace)
**     Description :
**         Registers the beginning of an Interrupt Service Routine.
**         This must not be interrupted by another ISR containing
**         recorder library calls, so if allowing nested ISRs this must
**         be called with interrupts disabled.  Method is always
**         enabled if 'Include ISR tracing' is set to 'yes' in the
**         properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**         id              - ID of the ISR
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceStoreISREnd(pendingISR) \
  vTraceStoreISREnd(pendingISR)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceStoreISREnd (component PercepioTrace)
**     Description :
**         Registers the end of an Interrupt Service Routine. This must
**         not be interrupted by another ISR containing recorder
**         library calls, so if allowing nested ISRs this must be
**         called with interrupts disabled.  Method is always enabled
**         if 'Include ISR tracing' is set to 'yes' in the properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pendingISR      - The parameter pendingISR
**                           indicates if the interrupt has requested a
**                           task-switch (= 1) or if the interrupt
**                           returns to the earlier context (= 0)
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceTaskSkipDefaultInstanceFinishedEvents() \
  vTraceTaskSkipDefaultInstanceFinishedEvents()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceTaskSkipDefaultInstanceFinishedEvents (component PercepioTrace)
**     Description :
**         This is useful if there are implicit Instance Finish Events,
**         such as vTaskDelayUntil or xQueueReceive, in a task where an
**         explicit Instance Finish Event has been defined. This
**         function tells the recorder that only the explicitly defined
**         functions, using vTraceTaskInstanceIsFinished, should be
**         treated as Instance Finish Events for this task. The
**         implicit Instance Finish Events are thus disregarded for
**         this task.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceTaskInstanceIsFinished() \
  vTraceTaskInstanceIsFinished()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceTaskInstanceIsFinished (component PercepioTrace)
**     Description :
**         This defines an explicit Instance Finish Event for the
**         current task. It tells the recorder that the current
**         instance of this task is finished at the next kernel call of
**         the task, e.g., a taskDelay or a queue receive. This
**         function should be called right before the api function call
**         considered to be the end of the task instance, i.e., the
**         Instance Finish Event.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceExcludeTaskFromSchedulingTrace(name) \
  vTraceExcludeTaskFromSchedulingTrace(name)

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceExcludeTaskFromSchedulingTrace (component PercepioTrace)
**     Description :
**         Excludes a task from the recording using a flag in the
**         Object Property Table. This can be useful if some irrelevant
**         task is very frequent and is "eating up the buffer". This
**         should be called the task has been created, but  before
**         starting the FreeRTOS scheduler.
**     Parameters  :
**         NAME            - DESCRIPTION
**         name            - name of the task
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceInitTraceData() \
  vTraceInitTraceData()

/*
** ===================================================================
**     Method      :  McuPercepio_vTraceInitTraceData (component PercepioTrace)
**     Description :
**         Allocates, if necessary, and initializes the recorder data
**         structure, based on the settings.
**     Parameters  : None
**     Returns     :
**         ---             - Pointer to trace data (RecorderDataType*)
** ===================================================================
*/

void McuPercepio_vGetGDBDumpCommand(uint8_t *buf, uint16_t bufSize, uint8_t *fileName);
/*
** ===================================================================
**     Method      :  McuPercepio_vGetGDBDumpCommand (component PercepioTrace)
**     Description :
**         Gets the gdb command to dump the trace data to a file.
**         Useful for copy-pasting it to the gdb console.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buf             - Pointer to buffer for the command. Make it
**                           large enoug (about 64 bytes)
**         bufSize         - size of the buffer
**       * fileName        - Pointer to the file name string,
**                           e.g. "C:\\tmp\\trace.dump"
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceSetStopHook(stopHookFunction) \
  vTraceSetStopHook(stopHookFunction)
/*
** ===================================================================
**     Method      :  McuPercepio_vTraceSetStopHook (component PercepioTrace)
**     Description :
**         Sets a function to be called when the recorder is stopped.
**     Parameters  :
**         NAME            - DESCRIPTION
**         stopHookFunction - 
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_xTraceGetLastError() \
  xTraceGetLastError()
/*
** ===================================================================
**     Method      :  McuPercepio_xTraceGetLastError (component PercepioTrace)
**     Description :
**         Gives the last error message, if any. NULL if no error
**         message is stored. Any error message is also presented when
**         opening a trace file.
**     Parameters  : None
**     Returns     :
**         ---             - Error message
** ===================================================================
*/

#define McuPercepio_vTraceClearError(resetErrorMessage) \
  vTraceClearError(resetErrorMessage)
/*
** ===================================================================
**     Method      :  McuPercepio_vTraceClearError (component PercepioTrace)
**     Description :
**         Removes any previous error message generated by recorder
**         calling vTraceError. By calling this function, it may be
**         possible to start/restart the trace despite errors in the
**         recorder, but there is no guarantee that the trace recorder
**         will work correctly in that case, depending on the type of
**         error.
**     Parameters  :
**         NAME            - DESCRIPTION
**         resetErrorMessage - parameter is
**                           not used
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define McuPercepio_vTraceTaskInstanceFinish() \
  vTraceTaskInstanceFinish() \
/*
** ===================================================================
**     Method      :  McuPercepio_vTraceTaskInstanceFinish (component PercepioTrace)
**     Description :
**         Marks the current task instance as finished on the next
**         kernel call.
**         If that kernel call is blocking, the instance ends after the
**         blocking event
**         and the corresponding return event is then the start of the
**         next instance.
**         If the kernel call is not blocking, the viewer instead
**         splits the current
**         fragment right before the kernel call, which makes this call
**         the first event
**         of the next instance.
**         See also USE_IMPLICIT_IFE_RULES in trcConfig.h
**         Example:
**         while(1)
**         {
**         xQueueReceive(CommandQueue, &command, timeoutDuration);
**         processCommand(command);
**         vTraceInstanceFinish();
**         }
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuPercepio_vTraceTaskInstanceFinishDirect() \
  vTraceTaskInstanceFinishDirect()
/*
** ===================================================================
**     Method      :  McuPercepio_vTraceTaskInstanceFinishDirect (component PercepioTrace)
**     Description :
**         Marks the current task instance as finished at this very
**         instant.
**         This makes the viewer to splits the current fragment at this
**         point and begin
**         a new actor instance.
**         See also USE_IMPLICIT_IFE_RULES in trcConfig.h
**         Example:
**         This example will generate two instances for each loop
**         iteration.
**         The first instance ends at vTraceInstanceFinishDirect(),
**         while the second
**         instance ends at the next xQueueReceive call.
**         while (1)
**         {
**         xQueueReceive(CommandQueue, &command, timeoutDuration);
**         ProcessCommand(command);
**         vTraceInstanceFinishDirect();
**         DoSometingElse();
**         vTraceInstanceFinish();
**         }
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END McuPercepio. */

#endif
/* ifndef __McuPercepio_H */
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
