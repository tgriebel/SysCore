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


	inline void Reset()
	{
		count = 0;
	}


	inline void Resize( uint32_t newCount )
	{
		if( newCount > N ) {
			newCount = N;
		}
		count = newCount;
	}


	inline void Append( const T& element )
	{
		const uint32_t newCount = ( count + 1 );
		if ( newCount <= N )
		{
			elements[ newCount - 1 ] = element;
			count = newCount;
		} else {
			assert( 0 );
		}
	}


	inline T* Ptr()
	{
		return &elements[ 0 ];
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