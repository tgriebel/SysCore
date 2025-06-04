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
#include <string>

bool FileExists( const std::string& path );
bool MakeDirectory( const std::string& path );
void SplitFileName( const std::string& path, std::string& fileName, std::string& ext );
void SplitPath( const std::string& path, std::string& directory, std::string& fileName );
void LeftTrim( std::string& s );
std::string LeftTrim( const std::string& s );
void RightTrim( std::string& s );
std::string RightTrim( const std::string& s );
void Trim( std::string& s );
std::string Trim( const std::string& s );
bool Equals( const std::string& str0, const std::string& str1 );
void ToLower( std::string& s );
std::string ToLower( const std::string& s );
void ToUpper( std::string& s );
std::string ToUpper( const std::string& s );
bool HasPrefix( const std::string& str0, const std::string& str1 );
bool HasSuffix( const std::string& str0, const std::string& str1 );
std::vector<char> ReadTextFile( const std::string& filename );
std::vector<char> ReadBinaryFile( const std::string& filename );