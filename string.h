#ifndef __STRING_H__
#define __STRING_H__

#include <stdio.h>

class String
{
public:
	String();
	String(const char*);
  String(const String& other);
	String(String&& other);
	String& operator=(String other);
	String& operator=(String&& other);
	~String();
	
	String* operator&()
	{
		return this;
	}

	const String* operator&() const
	{
		return this;
	}

	const char* Data() const
	{
		return data_;
	}

private:
	char* data_;
	int len_;
};



#endif //__STRING_H__
