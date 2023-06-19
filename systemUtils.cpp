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

#include <string>
#include <fstream>
#if defined _MSC_VER
#include<direct.h>
#endif

using namespace std;

bool FileExists( const string& path )
{
	ifstream stream( path.c_str() );
	const bool exist = stream.good();
	stream.close();
	return exist;
}


bool MakeDirectory( const string& path )
{
#if defined _MSC_VER
	return ( _mkdir( path.c_str() ) == 0 );
#else
	assert(0);
	return false;
#endif
}


void SplitFileName( const string& path, string& fileName, string& ext )
{
	size_t extPos = path.find_last_of( "." );

	fileName = path.substr( 0, extPos );
	ext = path.substr( extPos + 1, path.length() );
}


void SplitPath( const string& path, string& directory, string& fileName )
{
	size_t dirPos = path.find_last_of( "\\" ) + 1;
	directory = path.substr( 0, dirPos );
	fileName = path.substr( dirPos, path.length() );
}