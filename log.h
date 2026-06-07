#pragma once

#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace SysCore
{
template<typename T>
class Logger
{
public:
	using Frame		= std::vector<T>;
	using Records	= std::vector<Frame>;

private:
	Records		m_records;
	uint32_t	m_frameIndex;
	uint32_t	m_frameCount;

public:
    using Frame = std::vector<T>;
    using Records = std::vector<Frame>;

    Logger() : m_frameIndex( 0 ), m_frameCount( 0 )
    {
        Reset( 1 );
    }

    void Reset( uint32_t frameCount, uint32_t reservePerFrame = 0 )
    {
        m_records.clear();

        // +1 for the sentinel frame at index 0
        m_frameCount = frameCount + 1;
        m_frameIndex = 0;

        m_records.resize( m_frameCount );
        if ( reservePerFrame > 0 )
        {
            for ( Frame& frame : m_records ) {
                frame.reserve( reservePerFrame );
            }
        }
        NewFrame();
    }

    void NewFrame()
    {
        if ( IsFull() ) {
            return;
        }
        ++m_frameIndex;
    }

    T& NewEntry()
    {
        assert( m_frameCount > 0 );
        Frame& frame = m_records[ m_frameIndex ];
        frame.resize( frame.size() + 1 );
        return frame.back();
    }

    const Frame& GetFrame( uint32_t frameIndex ) const
    {
        const uint32_t safeIndex = ( frameIndex >= m_frameCount ) ? 0 : frameIndex;
        return m_records[ safeIndex ];
    }

    T& GetCurrentEntry()
    {
        assert( !m_records[ m_frameIndex ].empty() );
        return m_records[ m_frameIndex ].back();
    }

    const T& GetCurrentEntry() const
    {
        assert( !m_records[ m_frameIndex ].empty() );
        return m_records[ m_frameIndex ].back();
    }

    uint32_t GetRecordCount() const
    {
        return ( m_frameCount == 0 ) ? 0 : m_frameIndex + 1;
    }

    bool IsFull() const
    {
        assert( m_frameCount > 0 );
        return ( m_frameCount <= 1 ) || ( m_frameIndex >= ( m_frameCount - 1 ) );
    }

    bool IsFinished() const
    {
        return IsFull() && !m_records[ m_frameIndex ].empty();
    }
};

}
