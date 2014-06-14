
#include <VxWorks.h>
#include "FRCComm.h"
#include <Simulator/Simulator.h>
#include "LogMacros.h"

SEM_ID * packet_semaphore = NULL;

int getControlData(FRCControlData *data, char *userData, int wait_ms)
{
	//certain programs might have threads which keep going after the program is stopped and call down to this function
	if(!Simulator::GetInstance().isStarted)
	{
		LOG_ROBOT_RECOVERABLE("Some thread in user code has a lifetime problem and tried to access control data when the robot was stopped")
		return 0;
	}

	return Simulator::GetInstance().GetControlData(data, userData);
}

int setStatusData(float battery, UINT8 dsDigitalOut, const char *userData, int userDataLength, int wait_ms)
{
	return 0;
}

int setUserDsLcdData(const char *userDsLcdData, int userDsLcdDataLength, int wait_ms)
{
	Simulator::GetInstance().SetLCDData(userDsLcdData, userDsLcdDataLength);
	return 0;
}

void setNewDataSem(SEM_ID * sem)
{
	packet_semaphore = sem;
}

void setResyncSem(SEM_ID)
{
	LOG_NOT_IMPLEMENTED
}

void signalResyncActionDone(void)
{
	LOG_NOT_IMPLEMENTED
}

// this UINT32 is really a LVRefNum
void setNewDataOccurRef(UINT32 refnum)
{
	LOG_NOT_IMPLEMENTED
}

void setResyncOccurRef(UINT32 refnum)
{
	LOG_NOT_IMPLEMENTED
}

void FRC_NetworkCommunication_getVersionString(char *version)
{
	LOG_NOT_IMPLEMENTED
}

void PacketReady()
{
	if (packet_semaphore) *packet_semaphore = 0;
}
