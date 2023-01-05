#include "timer.h"

#include <chrono>
using namespace std::chrono;

void Timer::Start()
{
	startTimeMs = duration_cast<milliseconds>( steady_clock::now().time_since_epoch() );
	endTimeMs = startTimeMs;
}


void Timer::Stop()
{
	endTimeMs = duration_cast<milliseconds>( steady_clock::now().time_since_epoch() );
}


uint64_t Timer::GetElapsed() const
{
	return ( endTimeMs - startTimeMs ).count();
}


uint64_t Timer::GetCurrentElapsed() const
{
	const milliseconds time = duration_cast<milliseconds>( steady_clock::now().time_since_epoch() );
	return ( time - startTimeMs ).count();
}