#pragma once

/*
* MIT License
*
* Copyright( c ) 2026 Thomas Griebel
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

#include <assert.h>
#include <cstdint>
#include <vector>

#include "common.h"

namespace SysCore
{
void TestBitArray();

class BitArray
{
private:

	using ElementType = uint64_t;
	static constexpr uint32_t BitsPerElement = 8 * sizeof( ElementType );

	std::vector<ElementType> bits;

public:

	BitArray( uint32_t reserveBits = 1024 )
	{
		bits.resize( ( reserveBits + BitsPerElement - 1 ) / BitsPerElement );
	}

	void			Reset();

	void			Set( const uint32_t element );

	void			Clear( const uint32_t element );

	[[nodiscard]]
	uint32_t		Count() const;

	[[nodiscard]]
	bool			AnySet() const;

	[[nodiscard]]
	bool			NoneSet() const;

	[[nodiscard]]
	uint32_t		Size() const;

	[[nodiscard]]
	bool			IsSet( const uint32_t element ) const;
};
}