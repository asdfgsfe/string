#include <iostream>
#include "string.h"

int main()
{
	String str;
	String str2("abc");
	std::cout << str2.Data() << std::endl;

	String str3(str2);
	std::cout << str3.Data() << std::endl;
	
	String str4("efg");
	std::cout << str4.Data() << std::endl;
	
	str4 = str3;
	std::cout << str4.Data() << std::endl;

	String str5(String("qwer"));
	std::cout << str5.Data() << std::endl;

	String str6;
	//str6 = std::move(str5);
	//std::cout << str6.Data() << std::endl;

	return 0;
}
