#pragma once
#include <assert.h>
#include <cstdint>

template<class T, uint32_t N>
class Array
{
private:
	T			elements[N];
	T			trap;
	uint32_t	count;
public:

	Array() : count( 0 )
	{}

	inline T& operator[]( uint32_t index )
	{
		if ( index >= Count() )
		{
			assert( 0 );
			return trap;
		}
		return elements[ index ];
	}


	inline const T& operator[]( uint32_t index ) const
	{
		if ( index >= Count() )
		{
			assert( 0 );
			return trap;
		}
		return elements[ index ];
	}


	inline void Resize( unsigned int newCount )
	{
		if( newCount > N ) {
			newCount = N;
		}
		count = newCount;
	}


	inline uint32_t Count() const
	{
		return count;
	}


	inline uint32_t Capacity() const
	{
		return N;
	}
};