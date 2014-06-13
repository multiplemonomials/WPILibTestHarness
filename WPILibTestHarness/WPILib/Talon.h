/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef TALON_H
#define TALON_H

#include "PWM.h"
#include "SpeedController.h"
#include "PIDOutput.h"

/**
 * IFI Talon Speed Controller
 */
class Talon : public PWM, public SpeedController, public PIDOutput
{
public:
	explicit Talon(UINT32 channel);
	Talon(UINT32 slot, UINT32 channel);
	virtual ~Talon();
	void Set(float value);
	float Get();
	
	void PIDWrite(float output);

private:
	void InitTalon();
};

#endif

