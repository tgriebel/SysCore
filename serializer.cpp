#include "serializer.h"
#include "assert.h"

uint8_t* Serializer::GetPtr()
{
	return bytes;
}


void Serializer::SetPosition( const uint32_t index )
{
	this->index = 0;
}


void Serializer::Clear()
{
	memset( bytes, 0, CurrentSize() );
	SetPosition( 0 );
}


bool Serializer::Grow( const uint32_t sizeInBytes )
{
	if( sizeInBytes == 0 ) {
		return false;
	}

	const uint64_t chkSize = byteCount + static_cast<uint64_t>( sizeInBytes );
	if( chkSize >= static_cast<uint64_t>( MaxByteCount ) ) {
		return false;
	}

	const uint32_t oldCount = byteCount;
	byteCount += sizeInBytes;

	uint8_t* newBytes = new uint8_t[ byteCount ];
	if( bytes != nullptr ) {
		memcpy( newBytes, bytes, oldCount );
		delete[] bytes;
	}
	memset( newBytes + oldCount, 0, sizeInBytes );

	bytes = newBytes;
	return true;
}


uint32_t Serializer::CurrentSize() const
{
	return index;
}


uint32_t Serializer::BufferSize() const
{
	return byteCount;
}


bool Serializer::CanStore( const uint32_t sizeInBytes ) const
{
	return ( CurrentSize() + sizeInBytes <= BufferSize() );
}


void Serializer::SetEndian( serializeEndian_t endianMode )
{
	endian = endianMode;
}


void Serializer::SetMode( serializeMode_t serializeMode )
{
	mode = serializeMode;
}


serializeMode_t Serializer::GetMode() const
{
	return mode;
}


uint32_t Serializer::NewLabel( const char name[ serializerHeader_t::MaxNameLength ] )
{
	const uint32_t sectionIx = header.sectionCount;

	serializerHeader_t::section_t& section = header.sections[ sectionIx ];
	section.offset = index;
	strcpy_s< serializerHeader_t::MaxNameLength >( section.name, name );
	++header.sectionCount;

	return sectionIx;
}


void Serializer::EndLabel( const char name[ serializerHeader_t::MaxNameLength ] )
{
	serializerHeader_t::section_t* section;
	if ( FindLabel( name, &section ) )
	{
		section->size = ( index - section->offset );
	}
}


bool Serializer::FindLabel( const char name[ serializerHeader_t::MaxNameLength ], serializerHeader_t::section_t** outSection )
{
	for ( uint32_t i = 0; i < header.sectionCount; ++i )
	{
		serializerHeader_t::section_t& section = header.sections[ i ];
		if ( _strnicmp( name, section.name, serializerHeader_t::MaxNameLength ) == 0 )
		{
			*outSection = &section;
			return true;
		}
	}

	*outSection = nullptr;
	return false;
}


bool Serializer::Next( ref_t type )
{
	if ( !CanStore( type.size ) ) {
		assert( 0 ); // TODO: remove
		return false;
	}

	if ( mode == serializeMode_t::LOAD )
	{
		for ( uint32_t i = 0; i < type.size; ++i )
		{
			if ( endian == serializeEndian_t::BIG ) {
				type.convert.u8.e[ type.size - 1 - i ] = bytes[ index ];
			} else {
				type.convert.u8.e[ i ] = bytes[ index ];
			}
			++index;
		}
	}
	else if( mode == serializeMode_t::STORE )
	{
		for ( uint32_t i = 0; i < type.size; ++i )
		{
			if ( endian == serializeEndian_t::BIG ) {
				bytes[ index ] = type.convert.u8.e[ type.size - 1 - i ];
			} else {
				bytes[ index ] = type.convert.u8.e[ i ];
			}
			++index;
		}
	}
	return true;
}


bool Serializer::NextArray( uint8_t* u8, uint32_t sizeInBytes )
{
	if ( !CanStore( sizeInBytes ) ) {
		assert( 0 ); // TODO: remove
		return false;
	}

	if ( mode == serializeMode_t::LOAD ) {
		for ( uint32_t i = 0; i < sizeInBytes; ++i )
		{
			if ( endian == serializeEndian_t::BIG ) {
				u8[ sizeInBytes - 1 - i ] = bytes[ index ];
			} else {
				u8[ i ] = bytes[ index ];
			}
			++index;
		}
	}
	else {
		for ( uint32_t i = 0; i < sizeInBytes; ++i )
		{
			if ( endian == serializeEndian_t::BIG ) {
				bytes[ index ] = u8[ sizeInBytes - 1 - i ];
			} else {
				bytes[ index ] = u8[ i ];
			}
			++index;
		}
	}
	return true;
}