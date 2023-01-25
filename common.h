#pragma once

#include <cstdint>

const uint32_t KB_1 = 1024;
const uint32_t MB_1 = 1024 * KB_1;
const uint32_t GB_1 = 1024 * MB_1;

#define KB( N ) ( N * KB_1 )
#define MB( N ) ( N * MB_1 )
#define GB( N ) ( N * GB_1 )
#define COUNTARRAY( ary ) static_cast<uint32_t>( sizeof( ary ) / sizeof( ary[0] ) )