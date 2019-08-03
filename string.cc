#include <string.h>
#include <iostream>
#include "string.h"
	

String::String()
	: data_(nullptr), len_(0)
{}

String::String(const char* data)
{
	len_ = ::strlen(data);
	data_ = new char[len_ + 1];
	data_[len_] = '\0';
}

String::String(const String& other)
{
	if (&other == this)
	{
		return;
	}
  len_ = other.len_;
	data_ = new char[len_ + 1];
	::memcpy(data_, other.data_, len_);
	data_[len_] = '\0';
}

String::String(String&& other)
{
	if (&other == this)
	{
		return;
	}
	data_ = other.data_;
	len_ = other.len_;
	other.len_ = 0;
	other.data_ = nullptr;
}

String& String::operator=(String other)
{
	if (&other == this)
	{
		return *this;
	}
	std::swap(data_, other.data_);
	std::swap(len_, other.len_);
	return *this;
}

String& String::operator=(String&& other)
{
	if (&other == this)
	{
		return *this;
	}
	if (data_)
	{
		delete data_;
	}
	data_ = other.data_;
	len_ = other.len_;
	other.len_ = 0;
	other.data_ = nullptr;
	return *this;
}

String::~String()
{
	if (data_)
	{
		delete data_;
	}
}
