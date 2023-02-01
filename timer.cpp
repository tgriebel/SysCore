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