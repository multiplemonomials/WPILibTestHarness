
#ifndef TIMER_H
#define TIMER_H

#include "semLib.h"
#include "Base.h"

#include <Simulator/Simulator.h>

static inline 
void Wait(double time)
{
	Simulator::Wait(time);
}


#endif


