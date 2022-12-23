#pragma once

#include <assert.h>
#include <cstdint>

class refCount_t
{
public:
	refCount_t() = delete;

	refCount_t( const int count ) {
		assert( count > 0 );
		this->count = count;
	}
	inline int Add() {
		return ( count > 0 ) ? ++count : 0;
	}
	inline int Release() {
		return ( count > 0 ) ? --count : 0;
	}
	[[nodiscard]]
	inline int IsFree() const {
		return ( count <= 0 );
	}
private:
	int count; // Considered dead at 0
};

template<typename T>
class ptr_t
{
public:
	ptr_t()
	{
		this->object = nullptr;
		this->instances = nullptr;
	};

	ptr_t( const uint64_t handle )
	{
		this->object = new uint64_t( handle );
		this->instances = new refCount_t( 1 );
	}

	ptr_t( const ptr_t& handle )
	{
		if ( handle.IsValid() )
		{
			this->object = handle.object;
			this->instances = handle.instances;
			this->instances->Add();
		}
		else {
			this->object = nullptr;
			this->instances = nullptr;
		}
	}

	~ptr_t()
	{
		if ( IsValid() )
		{
			instances->Release();
			if ( instances->IsFree() )
			{
				delete instances;
				delete object;
			}
			instances = nullptr;
			object = nullptr;
		}
	}

	ptr_t& operator=( const ptr_t& handle )
	{
		if ( this != &handle )
		{
			this->~ptr_t();
			this->object = handle.object;
			this->instances = handle.instances;
			if ( handle.IsValid() ) {
				this->instances->Add();
			}
		}
		return *this;
	}

	bool operator==( const ptr_t& rhs ) const {
		return ( object == rhs.object );
	}

	bool operator!=( const ptr_t& rhs ) const {
		return ( object != rhs.object );
	}

	const T* operator->() const {
		return Get();
	}

	T* operator->() {
		return Get();
	}

	void Reset() {
		this->~ptr_t();
	}

	bool IsValid() const {
		return ( object != nullptr ) && ( instances != nullptr );
	}

	T* Get() {
		return ( IsValid() && ( instances->IsFree() == false ) ) ? object : nullptr;
	}

	const T* Get() const {
		return ( IsValid() && ( instances->IsFree() == false ) ) ? object : nullptr;
	}
private:
	T*			object;
	refCount_t*	instances;
};