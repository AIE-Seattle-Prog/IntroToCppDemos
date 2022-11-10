#pragma once

class String
{
	char * data;

	int length;

public:
	String();
	String(const char * cstr);

	//
	// RULE OF THREE
	// 
	// dtor
	~String();
	// copy ctor
	String(const String & other);
	// copy assign
	String & operator= (const String & other);

	//
	// RULE OF FIVE
	// 
	// move ctor
	String(String && other);
	// move assign
	String& operator=(String && other);

	const char * GetCString() const;
};
