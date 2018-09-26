#include "canfestival.h"
#include "ObjDictMaster.h"
#include "timer.h"
#include "user_canfestival.h"


unsigned int TimerAlarm=0;
unsigned int TimerCounter=0;		//时间计数


/************************** Modul variables **********************************/

void canOpenInit(UNS8 nodeId)
{
  setState(&ObjDictMaster_Data, Initialisation);	// Init the state
  setNodeId (&ObjDictMaster_Data, 0x7F);
  setState(&ObjDictMaster_Data, Operational);		// Put the master in operational mode
}

/******************************************************************************
Set the timer for the next alarm.
INPUT	value TIMEVAL (unsigned long)
OUTPUT	void
******************************************************************************/
void setTimer(TIMEVAL value)
{
  TimerAlarm =TimerCounter + value;	// Add the desired time to timer interrupt time
}

/******************************************************************************
Return the elapsed time to tell the stack how much time is spent since last call.
INPUT	void
OUTPUT	value TIMEVAL (unsigned long) the elapsed time
******************************************************************************/
TIMEVAL getElapsedTime(void)
{
	int ret =TimerAlarm > TimerCounter ? TimerAlarm - TimerCounter : 0;
	if(0==ret)
	{
		TimerCounter=0;
	}
  return ret;
}
//*----------------------------------------------------------------------------
//* Function Name       : timerForCan
//* Object              : C handler interrupt function by the interrupts
//*                       assembling routine
//* Output Parameters   : calls TimeDispatch
//*----------------------------------------------------------------------------
void timerForCan(void)
{
	TimerCounter++;
	
	if(TimerCounter>=TimerAlarm)
	{
    TimeDispatch();	// Call the time handler of the stack to adapt the elapsed time
	}
}

unsigned char canSend(CAN_PORT notused, Message *m)
{
	return 1;
}
