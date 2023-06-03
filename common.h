/*
* MIT License
*
* Copyright( c ) 2023 Thomas Griebel
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

#pragma once

#include <cstdint>

const uint32_t KB_1 = 1024;
const uint32_t MB_1 = 1024 * KB_1;
const uint32_t GB_1 = 1024 * MB_1;

#define KB( N ) ( N * KB_1 )
#define MB( N ) ( N * MB_1 )
#define GB( N ) ( N * GB_1 )
#define COUNTARRAY( ary ) static_cast<uint32_t>( sizeof( ary ) / sizeof( ary[0] ) )

#define DEFINE_ENUM_OPERATORS( enumType, intType )														\
inline void operator|=( enumType& lhs, const enumType rhs )												\
{																										\
	lhs = static_cast<enumType>( static_cast<intType>( lhs ) | static_cast<intType>( rhs ) );			\
}																										\
																										\
inline void operator&=( enumType& lhs, const enumType rhs )												\
{																										\
	lhs = static_cast<enumType>( static_cast<intType>( lhs ) & static_cast<intType>( rhs ) );			\
}																										\
																										\
inline enumType operator&( const enumType lhs, const enumType rhs )										\
{																										\
	return static_cast<enumType>( static_cast<intType>( lhs ) & static_cast<intType>( rhs ) );			\
}																										\
																										\
inline enumType operator|( const enumType lhs, const enumType rhs )										\
{																										\
	return static_cast<enumType>( static_cast<intType>( lhs ) | static_cast<intType>( rhs ) );			\
}																										\
																										\
inline enumType operator>>( const enumType lhs, const enumType rhs )									\
{																										\
	return static_cast<enumType>( static_cast<intType>( lhs ) >> static_cast<intType>( rhs ) );			\
}																										\
																										\
inline enumType operator<<( const enumType lhs, const enumType rhs )									\
{																										\
	return static_cast<enumType>( static_cast<intType>( lhs ) << static_cast<intType>( rhs ) );			\
}