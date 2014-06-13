/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef ANALOG_CHANNEL_H_
#define ANALOG_CHANNEL_H_

#include <Simulator/Simulator.h>

#include "SensorBase.h"
#include "PIDSource.h"

class AnalogModule;

/**
 * Analog channel class.
 * 
 * Each analog channel is read from hardware as a 12-bit number representing -10V to 10V.
 * 
 * Connected to each analog channel is an averaging and oversampling engine.  This engine accumulates
 * the specified ( by SetAverageBits() and SetOversampleBits() ) number of samples before returning a new
 * value.  This is not a sliding window average.  The only difference between the oversampled samples and
 * the averaged samples is that the oversampled samples are simply accumulated effectively increasing the
 * resolution, while the averaged samples are divided by the number of samples to retain the resolution,
 * but get more stable values.
 */
class AnalogChannel : public SensorBase, public PIDSource
{
public:
	static const UINT32 kAccumulatorSlot = 1;
	static const UINT32 kAccumulatorNumChannels = 2;
	static const UINT32 kAccumulatorChannels[kAccumulatorNumChannels];

	AnalogChannel(UINT32 slot, UINT32 channel){
		Simulator::GetInstance()->AddAnalogChannel(this, slot, channel);
	}
	explicit AnalogChannel(UINT32 channel){
		Simulator::GetInstance()->AddAnalogChannel(this, SensorBase::GetDefaultAnalogModule(), channel);
	}
	virtual ~AnalogChannel(){
		if (Simulator::GetInstance())
			Simulator::GetInstance()->DeleteAnalogChannel(this);
	}

	AnalogModule *GetModule();

	INT16 GetValue();
	INT32 GetAverageValue();

	float GetVoltage() { return m_value; }
	float GetAverageVoltage() { return m_value; }

	UINT32 GetSlot();
	UINT32 GetChannel();

	void SetAverageBits(UINT32 bits);
	UINT32 GetAverageBits();
	void SetOversampleBits(UINT32 bits);
	UINT32 GetOversampleBits();

	UINT32 GetLSBWeight();
	INT32 GetOffset();

	bool IsAccumulatorChannel();
	void InitAccumulator();
	void SetAccumulatorInitialValue(INT64 value);
	void ResetAccumulator();
	void SetAccumulatorCenter(INT32 center);
	void SetAccumulatorDeadband(INT32 deadband);
	INT64 GetAccumulatorValue();
	UINT32 GetAccumulatorCount();
	void GetAccumulatorOutput(INT64 *value, UINT32 *count);
	
	double PIDGet(){ return GetAverageVoltage(); }
	
	float m_value;
};

#endif
