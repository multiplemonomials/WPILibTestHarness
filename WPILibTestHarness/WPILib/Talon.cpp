/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Talon.h"


void Talon::InitTalon()
{
}

/**
 * Constructor that assumes the default digital module.
 * 
 * @param channel The PWM channel on the digital module that the Talon is attached to.
 */
Talon::Talon(UINT32 channel) : PWM(channel)
{
	InitTalon();
}

/**
 * Constructor that specifies the digital module.
 * 
 * @param slot The slot in the chassis that the digital module is plugged into.
 * @param channel The PWM channel on the digital module that the Talon is attached to.
 */
Talon::Talon(UINT32 slot, UINT32 channel) : PWM(slot, channel)
{
	InitTalon();
}

Talon::~Talon()
{
}

/**
 * Set the PWM value.  
 * 
 * The PWM value is set using a range of -1.0 to 1.0, appropriately
 * scaling the value for the FPGA.
 * 
 * @param speed The speed value between -1.0 and 1.0 to set.
 */
void Talon::Set(float speed)
{
	SetSpeed(speed);
}

/**
 * Get the recently set value of the PWM.
 * 
 * @return The most recently set value for the PWM between -1.0 and 1.0.
 */
float Talon::Get()
{
	return GetSpeed();
}

/**
 * Write out the PID value as seen in the PIDOutput base object.
 * 
 * @param output Write out the PWM value as was found in the PIDController
 */
void Talon::PIDWrite(float output) 
{
	Set(output);
}
