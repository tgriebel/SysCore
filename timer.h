#pragma once

#include <string>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		label = "";
		Start();
	}

	Timer( std::string _label )
	{
		label = _label;
		Start();
	}

	void		Start();
	void		Stop();

	[[nodiscard]]
	uint64_t	GetElapsed() const;

	[[nodiscard]]
	uint64_t	GetCurrentElapsed() const;

private:
	std::chrono::milliseconds	startTimeMs;
	std::chrono::milliseconds	endTimeMs;
	std::string					label;
};