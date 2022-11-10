#include "String.h"
#include <cstring>

const char * String::GetCString() const 
{
	return data;
}

String::String()
{
	data = new char[10];
	length = 10;
}

String::String(const char * cstr)
{
	// get the length of the cstr
	int len = strlen(cstr) + 1;
	length = len;

	// allocate an array big enough to hold it
	data = new char[len];

	// copy the data over
	for (int i = 0; i < length; ++i)
	{
		data[i] = cstr[i];
	}
}

String::~String()
{
	delete[] data;
}

String::String(const String & other)
{
	length = other.length;
	data = new char[length];

	for (int i = 0; i < length; ++i)
	{
		data[i] = other.data[i];
	} 
}

// copy assign
String & String::operator= (const String & other)
{
	if (length < other.length)
	{
		delete[] data;
		data = new char[other.length];
	}

	for (int i = 0; i < other.length; ++i)
	{
		data[i] = other.data[i];
	}

	return *this;
}

String::String(String && other)
{
	length = other.length;
	data = other.data;

	other.length = 0;
	other.data = nullptr;
}

String & String::operator=(String && other)
{
	length = other.length;
	data = other.data;

	other.length = 0;
	other.data = nullptr;

	return *this;
}
