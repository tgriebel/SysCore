/*
* MIT License
*
* Copyright( c ) 2022-2023 Thomas Griebel
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this softwareand associated documentation files( the "Software" ), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright noticeand this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "timer.h"

#include <iostream>
#include <assert.h>
#include <chrono>
using namespace std::chrono;

uint64_t Timer::Convert( const std::chrono::nanoseconds& start, const std::chrono::nanoseconds& end ) const
{
	if ( m_precision == NANOSECOND ) {
		return duration_cast<nanoseconds>( end - start ).count();
	}
	if ( m_precision == MICROSECOND ) {
		return duration_cast<microseconds>( end - start ).count();
	}
	if ( m_precision == MILLISECOND ) {
		return duration_cast<milliseconds>( end - start ).count();
	}
	if ( m_precision == SECOND ) {
		return duration_cast<seconds>( end - start ).count();
	}
}


timerPrecision_t Timer::GetPrecision() const
{
	return m_precision;
}


std::string	Timer::GetLabel() const
{
	return m_label;
}


void Timer::Start()
{
	m_startTime = duration_cast<nanoseconds>( steady_clock::now().time_since_epoch() );
	m_endTime = m_startTime;
}


void Timer::Stop()
{
	m_endTime = duration_cast<nanoseconds>( steady_clock::now().time_since_epoch() );
}


uint64_t Timer::GetElapsed() const
{
	return Convert( m_startTime, m_endTime );
}


void Timer::SetPrecision( const timerPrecision_t precision )
{
	m_precision = precision;
}


uint64_t Timer::GetCurrentElapsed() const
{
	const nanoseconds time = duration_cast<nanoseconds>( steady_clock::now().time_since_epoch() );
	return Convert( m_startTime, time );
}


void TimerPrint( const Timer* timer )
{
	assert( timer != nullptr );

	const timerPrecision_t precision = timer->GetPrecision();
	std::string precisionStr = "";
	switch( precision )
	{
		case NANOSECOND: precisionStr = "ns"; break;
		case MICROSECOND: precisionStr = "us"; break;
		case MILLISECOND: precisionStr = "ms"; break;
		case SECOND: precisionStr = "s"; break;
	}
	
	std::cout << "Timer(" << timer->GetLabel() << "): " << timer->GetCurrentElapsed() << precisionStr << std::endl;
}