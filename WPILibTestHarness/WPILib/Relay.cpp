/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.	       				      */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/


#include <Relay.h>

Relay::Relay(uint8_t moduleNumber, uint32_t channel, Relay::Direction direction)
: m_channel (channel)
, m_direction (direction)
{
	InitRelay(moduleNumber);
}

Relay::Relay(uint32_t channel, Relay::Direction direction)
: m_channel (channel)
, m_direction (direction)
{
	InitRelay(GetDefaultDigitalModule());
}

void Relay::Set(Relay::Value value)
{
	return;
}


/**
* Get the Relay State
*
* Gets the current state of the relay.
*
* When set to kForwardOnly or kReverseOnly, value is returned as kOn/kOff not
* kForward/kReverse (per the recommendation in Set)
*
* @return The current state of the relay as a Relay::Value
*/
Relay::Value Relay::Get() 
{
	return kOff;
}

ITable * Relay::GetTable()
{
	return m_table;
}

