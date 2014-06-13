/*
    WPILib Test Harness
    Copyright (C) 2009 Dustin Spicuzza <dustin@virtualroadside.com>
	
	$Id: SimulationData.h 304 2009-03-14 09:31:05Z dspicuzz $

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License v3 as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SIMULATOR_SIMULATIONDATA_H
#define SIMULATOR_SIMULATIONDATA_H

#include <vector>

#define ANALOG_SLOT_1 	1
#define ANALOG_SLOT_2 	2
#define DIGITAL_SLOT_1 	4
#define DIGITAL_SLOT_2 	6
#define SOLENOID_SLOT_1 8

#define DIGITAL_PWM_CHANNELS 	10
#define DIGITAL_IO_CHANNELS 	14
#define DIGITAL_RELAY_CHANNELS 	8

#define ANALOG_IO_CHANNELS 		8

#define SOLENOID_IO_CHANNELS	8


class Encoder;
class Gyro;
class PWM;
class DigitalInput;
class DigitalOutput;
class AnalogChannel;
class Solenoid;


struct EncoderInfo {
	Encoder * encoder;
	UINT32 slota, slotb;
	UINT32 channela, channelb;
	
	int count;
	
	EncoderInfo(Encoder * e, UINT32 sa, UINT32 ca, UINT32 sb, UINT32 cb) :
		encoder(e), slota(sa), slotb(sb), channela(ca), channelb(cb), count(0)
	{}
	
	void Transfer();
};



struct GyroInfo {
	Gyro *	gyro;
	UINT32	slot;
	UINT32	channel;
	
	float	angle;
	
	GyroInfo(Gyro * g, UINT32 s, UINT32 c) :
		gyro(g), slot(s), channel(c), angle(0.0)
	{}
	
	// only called by the simulation
	void Transfer();
};


struct DigitalIOData {
	DigitalInput * digitalInput;
	DigitalOutput * digitalOutput;

	bool used;
	bool value;
	
	DigitalIOData() : 
		digitalInput(NULL), digitalOutput(NULL), used(false), value(false)
	{}
	
	// only called by the simulation
	void Transfer();
};

struct PWMData {
	PWM * pwm;
	float speed;
	
	PWMData() : 
		pwm(NULL), speed(0.0)
	{}
	
	// only called by the simulation
	void Transfer();
};

struct RelayData {
	bool used;
	
	/// @todo implement this
	RelayData() : 
		used(false) 
	{}
	
	void Transfer();
};

struct DigitalModuleData {

	DigitalIOData 	io[DIGITAL_IO_CHANNELS];
	PWMData 		pwm[DIGITAL_PWM_CHANNELS];
	RelayData		relay[DIGITAL_RELAY_CHANNELS];
	
	// only called by the simulation
	void Transfer()
	{
		for (size_t i = 0; i < DIGITAL_IO_CHANNELS; i++)
			io[i].Transfer();
		for (size_t i = 0; i < DIGITAL_PWM_CHANNELS; i++)
			pwm[i].Transfer();
		for (size_t i = 0; i < DIGITAL_RELAY_CHANNELS; i++)
			relay[i].Transfer();
	}
};

struct AnalogIOData {

	AnalogChannel * analogChannel;

	bool used;
	float value;	// 0-5v
	
	AnalogIOData() :
		analogChannel(NULL), used(false), value(5.0)
	{}
	
	// only called by the simulation
	void Transfer();
};

struct AnalogModuleData 
{
	AnalogIOData io[ANALOG_IO_CHANNELS];
	
	void Transfer()
	{
		for (size_t i = 0; i < ANALOG_IO_CHANNELS; i++)
			io[i].Transfer();
	}
};

struct SolenoidData {
	Solenoid * solenoid;

	bool value;
	
	SolenoidData() : 
		solenoid(NULL), value(false)
	{}
	
	// only called by the simulation
	void Transfer();
};

struct SolenoidModule {
	SolenoidData solenoids[SOLENOID_IO_CHANNELS];

	void Transfer()
	{
		for (size_t i = 0; i < SOLENOID_IO_CHANNELS; i++)
			solenoids[i].Transfer();
	}
};



// this is copied by value, so don't make it too obscene
struct SimulationData
{
	// lcd information
	char lcdText[21 * 6 + 2];

	// raw io
	AnalogModuleData 	analogModule[2];
	DigitalModuleData 	digitalModule[2];
	SolenoidModule		solenoidModule;
	
	// encoders, gyros
	std::vector<EncoderInfo> encoders;
	std::vector<GyroInfo>	gyros;
	
	
	// default constructor
	SimulationData() 
	{
		memset(lcdText, ' ', sizeof(lcdText));
	}
	
	// transfers the data to/from the simulation space
	void Transfer()
	{
		digitalModule[0].Transfer();
		digitalModule[1].Transfer();
		
		analogModule[0].Transfer();
		analogModule[1].Transfer();
		
		solenoidModule.Transfer();
		
		for (size_t i = 0; i < encoders.size(); i++)
			encoders[i].Transfer();
			
		for (size_t i = 0; i < gyros.size(); i++)
			gyros[i].Transfer();
	}
};

#endif
