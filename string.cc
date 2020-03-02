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
    memcpy(data_, data, len_);
	data_[len_] = '\0';
}

String::String(const String& other)
{
	//错误 拷贝构造函数不用 处理自我赋值
  //if (&other == this)
	//{
		//return;
	//}
  	len_ = other.len_;
	data_ = new char[len_ + 1];
	::memcpy(data_, other.data_, len_);
	data_[len_] = '\0';
}

String::String(String&& other)
{
	//if (&other == this)
	//{
		//return;
	//}
	data_ = other.data_;
	len_ = other.len_;
	other.len_ = 0;
	other.data_ = nullptr;
}

String& String::operator=(/*String other*/ const String& other)
{
	//传进来一个值 然后换 是一个不好得方法 会阻碍编译器生成好的代码
    //判断this的目的是为了 自己把自己析构掉 然后再考呗 就啥都没有了
  if (&other == this)
	{
		return *this;
	}
	//std::swap(data_, other.data_);
	//std::swap(len_, other.len_);

  //正确应该
  String tmp(other);
  std::swap(*this, tmp);
	return *this;
}

String& String::operator=(String&& other)
{
	if (&other == this)
	{
		return *this;
	}
	//if (data_)
	//{
	//	delete[] data_;
	//}
    ~String();//这里改为调用析构函数
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
		delete[] data_;
        len_ = 0;
	}
}
